--- src/wayland-shm.c.orig	2016-11-18 00:32:40 UTC
+++ src/wayland-shm.c
@@ -30,6 +30,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -59,6 +61,9 @@ struct wl_shm_pool {
 	char *data;
 	int32_t size;
 	int32_t new_size;
+#ifdef HAVE_SYS_UCRED_H
+	int fd;
+#endif
 };
 
 struct wl_shm_buffer {
@@ -76,15 +81,24 @@ struct wl_shm_sigbus_data {
 	int fallback_mapping_used;
 };
 
+static void *mremap_compat_maymove(void *, size_t, size_t, int, int, int);
+
 static void
 shm_pool_finish_resize(struct wl_shm_pool *pool)
 {
 	void *data;
+	int fd = -1;
 
 	if (pool->size == pool->new_size)
 		return;
 
-	data = mremap(pool->data, pool->size, pool->new_size, MREMAP_MAYMOVE);
+#ifdef HAVE_SYS_UCRED_H
+	fd = pool->fd;
+#endif
+
+	data = mremap_compat_maymove(pool->data, pool->size, pool->new_size,
+				     PROT_READ | PROT_WRITE, MAP_SHARED, fd);
+
 	if (data == MAP_FAILED) {
 		wl_resource_post_error(pool->resource,
 				       WL_SHM_ERROR_INVALID_FD,
@@ -110,6 +124,10 @@ shm_pool_unref(struct wl_shm_pool *pool,
 	if (pool->internal_refcount + pool->external_refcount)
 		return;
 
+#ifdef HAVE_SYS_UCRED_H
+	close(pool->fd);
+#endif
+
 	munmap(pool->data, pool->size);
 	free(pool);
 }
@@ -223,6 +241,73 @@ shm_pool_destroy(struct wl_client *clien
 	wl_resource_destroy(resource);
 }
 
+#ifdef HAVE_MREMAP
+static void *
+mremap_compat_maymove(void *old_address, size_t old_size, size_t new_size,
+		      int old_prot, int old_flags, int old_fd)
+{
+	return mremap(old_address, old_size, new_size, MREMAP_MAYMOVE);
+}
+#else
+static void *
+mremap_compat_maymove(void *old_address, size_t old_size, size_t new_size,
+		      int old_prot, int old_flags, int old_fd)
+{
+	/* FreeBSD doesn't support mremap() yet, so we have to emulate it.
+	 * This assumes MREMAP_MAYMOVE is the only flag in use. */
+	if (new_size == old_size) {
+		return old_address;
+	} else if (new_size < old_size) {
+		/* Shrinking: munmap() the spare region. */
+		munmap(old_address + old_size, new_size - old_size);
+		return old_address;
+	} else {
+		void *ret;
+
+		/* Growing. Try and mmap() the extra region at the end of
+		 * our existing allocation. If that gets mapped in the
+		 * wrong place, fall back to mmap()ing an entirely new
+		 * region of new_size and copying the data across. */
+		ret = mmap(old_address + old_size, new_size - old_size,
+			   old_prot, old_flags, old_fd, 0);
+
+/* FIXME TODO: msync() before munmap()? */
+		if (ret == MAP_FAILED) {
+			/* Total failure! */
+			return ret;
+		} else if (ret == old_address + old_size) {
+			/* Success. */
+			return old_address;
+		} else if (ret != old_address + old_size) {
+			/* Partial failure. Fall back to mapping an
+			 * entirely new region. Unmap the region we
+			 * just mapped first. */
+			munmap(ret, new_size - old_size);
+
+			/* Map an entirely new region. */
+			ret = mmap(NULL, new_size,
+				   old_prot, old_flags, old_fd, 0);
+			if (ret == MAP_FAILED) {
+				/* Total failure! */
+				return ret;
+			}
+
+			/* Copy the old data across. Implicit assumption
+			 * that the old and new regions don't overlap. */
+			memcpy(ret, old_address, old_size);
+
+			/* Unmap the old region. */
+			munmap(old_address, old_size);
+
+			return ret;
+		}
+	}
+
+	/* Unreachable. */
+	return MAP_FAILED;
+}
+#endif
+
 static void
 shm_pool_resize(struct wl_client *client, struct wl_resource *resource,
 		int32_t size)
@@ -284,7 +369,14 @@ shm_create_pool(struct wl_client *client
 				       "failed mmap fd %d", fd);
 		goto err_free;
 	}
+
+#ifdef HAVE_SYS_UCRED_H
+	/* We need to keep the FD around on FreeBSD so we can implement
+	 * mremap(). See: mremap_compat_maymove(). */
+	pool->fd = fd;
+#else
 	close(fd);
+#endif
 
 	pool->resource =
 		wl_resource_create(client, &wl_shm_pool_interface, 1, id);

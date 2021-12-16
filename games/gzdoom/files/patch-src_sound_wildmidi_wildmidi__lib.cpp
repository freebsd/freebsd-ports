--- src/sound/wildmidi/wildmidi_lib.cpp.orig	2019-05-04 19:58:35 UTC
+++ src/sound/wildmidi/wildmidi_lib.cpp
@@ -1318,11 +1318,9 @@ static int load_sample(struct _patch *sample_patch) {
 }
 
 static struct _patch *
-get_patch_data(unsigned short patchid) {
+get_patch_data_locked(unsigned short patchid) {
 	struct _patch *search_patch;
 
-	std::lock_guard<std::mutex> lock(patch_lock);
-
 	search_patch = patch[patchid & 0x007F];
 
 	if (search_patch == NULL) {
@@ -1335,12 +1333,32 @@ get_patch_data(unsigned short patchid) {
 		}
 		search_patch = search_patch->next;
 	}
 	if ((patchid >> 8) != 0) {
-		return (get_patch_data(patchid & 0x00FF));
+		return (get_patch_data_locked(patchid & 0x00FF));
 	}
 	return NULL;
 }
 
+static struct _patch *
+get_patch_data(unsigned short patchid) {
+	struct _patch *patch;
+
+	/*
+	 * Uh, hey, no, sorry pal, you can't use this
+	 * construction here. This function can call itself
+	 * recursively, which means you will recursively
+	 * try to acquire the patch_lock mutex, which is
+	 * not allowed with lock_guard.
+	 */
+
+/*	std::lock_guard<std::mutex> lock(patch_lock); */
+
+	patch_lock.lock();
+	patch = get_patch_data_locked(patchid);
+	patch_lock.unlock();
+	return (patch);
+}
+
 static void load_patch(struct _mdi *mdi, unsigned short patchid) {
 	unsigned int i;
 	struct _patch *tmp_patch = NULL;

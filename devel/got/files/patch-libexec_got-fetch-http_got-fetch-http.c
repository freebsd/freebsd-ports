https://got.gameoftrees.org/?action=diff&commit=539ba663896a5eb0dd33d8f4027755974431d528&headref=HEAD&path=got.git

--- libexec/got-fetch-http/got-fetch-http.c.orig	2025-03-21 16:37:10 UTC
+++ libexec/got-fetch-http/got-fetch-http.c
@@ -1,6 +1,6 @@
 /*
  * Copyright (c) 2024 Tobias Heider <me@tobhe.de>
- * Copyright (c) 2022 Omar Polo <op@openbsd.org>
+ * Copyright (c) 2022, 2025 Omar Polo <op@openbsd.org>
  *
  * Permission to use, copy, modify, and distribute this software for any
  * purpose with or without fee is hereby granted, provided that the above
@@ -65,19 +65,6 @@ bufio_getdelim_sync(struct bufio *bio, const char *nl,
 	return buf_getdelim(&bio->rbuf, nl, len);
 }
 
-static size_t
-bufio_drain_sync(struct bufio *bio, void *d, size_t len)
-{
-	int	r;
-
-	do {
-		r = bufio_read(bio);
-		if (r == -1 && errno != EAGAIN)
-			errx(1, "bufio_read: %s", bufio_io_err(bio));
-	} while (r == -1 && errno == EAGAIN);
-	return bufio_drain(bio, d, len);
-}
-
 static void
 bufio_close_sync(struct bufio *bio)
 {
@@ -269,53 +256,81 @@ static ssize_t
 }
 
 static ssize_t
-http_read(struct bufio *bio, int chunked, size_t *chunksz, char *buf, size_t bufsz)
+http_read(struct bufio *bio, int chunked, size_t *chunksz, char *buf, size_t bufsz,
+    FILE *out)
 {
+	struct buf	*rbuf = &bio->rbuf;
 	const char	*errstr;
-	char		*line = NULL;
-	size_t		 r;
-	ssize_t		 ret = 0, linelen;
+	char		*chunk, *endln;
+	size_t		 avail, w;
+	ssize_t		 r, ret = 0;
 
-	if (!chunked)
-		return bufio_drain_sync(bio, buf, bufsz);
+	while (out != NULL || bufsz > 0) {
+		if (rbuf->cur == rbuf->len) {
+			rbuf->cur = 0;
+			rbuf->len = 0;
+			r = bufio_read(bio);
+			if (r == -1) {
+				warnx("bufio_read: %s", bufio_io_err(bio));
+				return (-1);
+			}
+			if (r == 0)
+				return ret;
+		}
 
-	while (bufsz > 0) {
-		if (*chunksz == 0) {
-		again:
-			line = bufio_getdelim_sync(bio, "\r\n", &linelen);
-			if (line == NULL) {
-				buf_drain(&bio->rbuf, linelen);
+		if (chunked && *chunksz == 0) {
+			for (;;) {
+				chunk = rbuf->buf + rbuf->cur;
+				avail = rbuf->len - rbuf->cur;
+				endln = memmem(chunk, avail, "\r\n", 2);
+				if (endln == NULL) {
+					r = bufio_read(bio);
+					if (r == -1) {
+						warnx("bufio_read: %s",
+						    bufio_io_err(bio));
+						return (-1);
+					}
+					if (r == 0)
+						return ret;
+					continue;
+				}
+				rbuf->cur += (endln - chunk) + 2;
+				*endln = '\0';
+				/* was the CRLF after the chunk? */
+				if (chunk == endln)
+					continue;
 				break;
 			}
-			if (*line == '\0') {
-				buf_drain(&bio->rbuf, linelen);
-				goto again; /* was the CRLF after the chunk */
-			}
 
-			*chunksz = hexstrtonum(line, 0, INT_MAX, &errstr);
+			*chunksz = hexstrtonum(chunk, 0, INT_MAX, &errstr);
 			if (errstr != NULL) {
 				warnx("invalid HTTP chunk: size is %s (%s)",
-				    errstr, line);
-				ret = -1;
-				break;
+				    errstr, chunk);
+				return (-1);
 			}
 
-			if (*chunksz == 0) {
-				buf_drain(&bio->rbuf, linelen);
+			if (*chunksz == 0)
 				break;
-			}
-			buf_drain(&bio->rbuf, linelen);
 		}
 
-		r = bufio_drain_sync(bio, buf, MINIMUM(*chunksz, bufsz));
-		if (r == 0) {
-			break;
+		avail = rbuf->len - rbuf->cur;
+		if (chunked && avail > *chunksz)
+			avail = *chunksz;
+
+		if (out != NULL) {
+			w = fwrite(rbuf->buf + rbuf->cur, 1, avail, out);
+			if (w != avail)
+				return (-1);
+		} else {
+			avail = MINIMUM(avail, bufsz);
+			memcpy(buf, rbuf->buf + rbuf->cur, avail);
 		}
 
-		ret += r;
-		buf += r;
-		bufsz -= r;
-		*chunksz -= r;
+		rbuf->cur += avail;
+		ret += avail;
+		buf += avail;
+		bufsz -= avail;
+		*chunksz -= avail;
 	}
 
 	return ret;
@@ -375,7 +390,7 @@ get_refs(int https, const char *host, const char *port
 		goto err;
 
 	/* skip first pack; why git over http is like this? */
-	r = http_read(&bio, chunked, &chunksz, buf, 4);
+	r = http_read(&bio, chunked, &chunksz, buf, 4, NULL);
 	if (r <= 0)
 		goto err;
 
@@ -388,23 +403,13 @@ get_refs(int https, const char *host, const char *port
 	/* TODO: validate it's # service=git-upload-pack\n */
 	while (skip > 0) {
 		r = http_read(&bio, chunked, &chunksz, buf,
-		    MINIMUM(skip, sizeof(buf)));
+		    MINIMUM(skip, sizeof(buf)), NULL);
 		if (r <= 0)
 			goto err;
 		skip -= r;
 	}
 
-	for (;;) {
-		r = http_read(&bio, chunked, &chunksz, buf, sizeof(buf));
-		if (r == -1)
-			goto err;
-
-		if (r == 0)
-			break;
-
-		fwrite(buf, 1, r, stdout);
-	}
-
+	http_read(&bio, chunked, &chunksz, NULL, 0, stdout);
 	fflush(stdout);
 	ret = 0;
 err:
@@ -497,16 +502,7 @@ upload_request(int https, const char *host, const char
 		goto err;
 
 	/* Fetch pack file data from server. */
-	for (;;) {
-		r = http_read(&bio, chunked, &chunksz, buf, sizeof(buf));
-		if (r == -1)
-			goto err;
-
-		if (r == 0)
-			break;
-
-		fwrite(buf, 1, r, stdout);
-	}
+	http_read(&bio, chunked, &chunksz, NULL, 0, stdout);
 
 	ret = 0;
 err:

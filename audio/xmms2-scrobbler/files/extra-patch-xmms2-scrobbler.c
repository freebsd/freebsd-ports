--- src/xmms2-scrobbler.c.orig	2009-12-30 17:04:01 UTC
+++ src/xmms2-scrobbler.c
@@ -140,93 +140,126 @@ signal_handler (int sig)
 		keep_running = false;
 }
 
-static size_t
-handle_handshake_reponse (void *rawptr, size_t size, size_t nmemb,
-                          void *data)
-{
-	Server *server = data;
-	size_t total = size * nmemb, left = total;
-	char *ptr = rawptr, *newline;
-	int len;
+char * get_line_from_response (char *answer, int lfpos) {
+    int lfpositions[10];
+    int i, k, lfcounter, start, end, resultlen;
 
-	newline = memchr (ptr, '\n', left);
-	if (!newline) {
-		fprintf (stderr, "no newline (1)\n");
-		return total;
-	}
+    char *result;
 
-	*newline = 0;
+#ifdef DEBUG
+    fprintf (stderr, "DEBUG: got string: %s\n", answer);
+#endif
 
-	if (strcmp (ptr, "OK")) {
-		fprintf (stderr, "handshake failed\n");
-		return total;
+    /* marking the string */
+    i = 0;
+    lfcounter = 0;
+    while (answer[i] != '\0') {
+	if (answer[i] == '\n' && lfcounter < 10) {
+	    lfpositions[lfcounter] = i;
+	    lfcounter++;
+#ifdef DEBUG
+	    fprintf (stderr, "DEBUG: got LF location: %d\n", i);
+#endif
 	}
+	i++;
+    }
+    /* getting the actual line */
+    /* getting the size of it */
 
-	len = newline - ptr + 1;
+    start = lfpos - 1;
+    end = lfpos;
+#ifdef DEBUG
+    if (start >= 0) {
+	fprintf (stderr, "DEBUG: requested line starts at char no. %d and ends at %d.\n", lfpositions[start], lfpositions[end]);
+    } else {
+	fprintf (stderr, "DEBUG: requested line starts at the start of string and ends at char no. %d.\n", lfpositions[end]);
+    }
+#endif
 
-	left -= len;
-	ptr += len;
+    if (start >= 0) {
+	resultlen = lfpositions[end] - lfpositions[start] + 1;
+    } else {
+	resultlen = lfpositions[end] + 1;
+    }
+#ifdef DEBUG
+    fprintf (stderr, "DEBUG: requested line will need %d bytes.\n", resultlen);
+#endif
+    result = malloc(resultlen);
+    bzero(result, resultlen);
 
-	newline = memchr (ptr, '\n', left);
-	if (!newline) {
-		fprintf (stderr, "no newline (1)\n");
-		return total;
+    /* bytecopying the line */
+#ifdef DEBUG
+    if (start >= 0) {
+	fprintf (stderr, "DEBUG: copying the string from char no. %d to %d.\n", lfpositions[start], lfpositions[end]);
+    } else {
+	fprintf (stderr, "DEBUG: copying the string from the beginning to char no. %d.\n", lfpositions[end]);
+    }
+#endif
+    k = 0;
+    if (start >= 0) {
+	i = lfpositions[start];
+    } else {
+	i = 0;
+    }
+    while (i < lfpositions[end]) {
+	/* don't copy LF themselves */
+	if (answer[i] != '\n') {
+	    result[k] = answer[i];
+	    k++;
 	}
+	i++;
+    }
 
-	*newline = 0;
-
-	len = newline - ptr + 1;
+#ifdef DEBUG
+    fprintf (stderr, "DEBUG: returning string: %s\n", result);
+#endif
+    return(result);
+}
 
-	if (len > 255) {
-		fprintf (stderr, "session ID is too long (%i characters)\n", len);
-		return total;
-	}
+static size_t
+handle_handshake_reponse (void *rawptr, size_t size, size_t nmemb,
+                          void *data)
+{
+	Server *server;
+	size_t total, left;
+	char *ptr, *status, *sessionid, *np_url, *subm_url;
 
-	strcpy (server->session_id, ptr);
+	server = data;
+	ptr = rawptr;
+	total = size * nmemb;
+	left = total;
 
-	left -= len;
-	ptr += len;
+#ifdef DEBUG
+	fprintf (stderr, "DEBUG: got string \"%s\".\n", rawptr);
+#endif
 
-	/* now playing URL */
-	newline = memchr (ptr, '\n', left);
-	if (!newline) {
-		fprintf (stderr, "no newline (2)\n");
-		return total;
+	status = get_line_from_response(rawptr, 0);
+	
+	if (strcmp(status, "OK") != 0) {
+	    fprintf (stderr, "WARNING: handshake failed: %s.\n", status);
+	    return(total);
 	}
 
-	*newline = 0;
-
-	len = newline - ptr + 1;
-
-	if (len > 255) {
-		fprintf (stderr, "now_playing URL is too long "
-		         "(%i characters)\n", len);
-		return total;
+	sessionid = get_line_from_response(rawptr, 3);
+	if (strlen(sessionid) > 255) {
+	    fprintf (stderr, "ERROR: session ID is too long (%ld characters).\n", strlen(sessionid));
+	    return(total);
 	}
+	strcpy (server->session_id, sessionid);
 
-	strcpy (server->np_url, ptr);
-
-	left -= len;
-	ptr += len;
-
-	/* submission URL */
-	newline = memchr (ptr, '\n', left);
-	if (!newline) {
-		printf("no newline (3)\n");
-		return total;
+	np_url = get_line_from_response(rawptr, 6);
+	if (strlen(np_url) > 255) {
+	    fprintf (stderr, "ERROR: nowplaying URL is too long (%ld characters).\n", strlen(np_url));
+	    return(total);
 	}
+	strcpy (server->np_url, np_url);
 
-	*newline = 0;
-
-	len = newline - ptr + 1;
-
-	if (len > 255) {
-		fprintf (stderr, "submission URL is too long "
-		         "(%i characters)\n", len);
-		return total;
+	subm_url = get_line_from_response(rawptr, 9);
+	if (strlen(sessionid) > 255) {
+	    fprintf (stderr, "ERROR: submission URL is too long (%ld characters).\n", strlen(subm_url));
+	    return(total);
 	}
-
-	strcpy (server->subm_url, ptr);
+	strcpy (server->subm_url, subm_url);
 
 	fprintf (stderr, "got:\n'%s' '%s' '%s'\n",
 	         server->session_id, server->np_url, server->subm_url);

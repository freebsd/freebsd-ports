--- src/lhext.c.orig	2000-10-04 14:57:38 UTC
+++ src/lhext.c
@@ -143,13 +143,13 @@ adjust_info(name, hdr)
 	char           *name;
 	LzHeader       *hdr;
 {
-	time_t          utimebuf[2];
+	struct utimbuf  utimebuf;
 
 	/* adjust file stamp */
-	utimebuf[0] = utimebuf[1] = hdr->unix_last_modified_stamp;
+	utimebuf.actime = utimebuf.modtime = hdr->unix_last_modified_stamp;
 
 	if ((hdr->unix_mode & UNIX_FILE_TYPEMASK) != UNIX_FILE_SYMLINK)
-		utime(name, utimebuf);
+		utime(name, &utimebuf);
 
 	if (hdr->extend_type == EXTEND_UNIX
 	    || hdr->extend_type == EXTEND_OS68K
@@ -190,8 +190,13 @@ extract_one(afp, hdr)
 		q = (char *) rindex(hdr->name, '/') + 1;
 	}
 	else {
+		if (is_directory_traversal(q)) {
+		  fprintf(stderr, "Possible directory traversal hack attempt in %s\n", q);
+		  exit(111);
+		}
+
 		if (*q == '/') {
-			q++;
+			while (*q == '/') { q++; }
 			/*
 			 * if OSK then strip device name
 			 */
@@ -351,10 +356,13 @@ extract_one(afp, hdr)
 				}
 
 				unlink(bb1);
+				make_parent_path(bb1);
 				l_code = symlink(bb2, bb1);
 				if (l_code < 0) {
-					if (quiet != TRUE)
-						warning("Can't make Symbolic Link : ");
+					if (quiet != TRUE) {
+						sprintf(buf, "%s -> %s", bb1, bb2);
+						warning("Can't make Symbolic Link : ", buf);
+					}
 				}
 				if (quiet != TRUE) {
 					printf("Symbolic Link %s -> %s\n", bb1, bb2);
@@ -419,6 +427,33 @@ cmd_extract()
 	return;
 }
 
+int
+is_directory_traversal(char *string)
+{
+  unsigned int type = 0; /* 0 = new, 1 = only dots, 2 = other chars than dots */
+  char *temp;
+
+  temp = string;
+
+  while (*temp != 0) {
+    if (temp[0] == '/') {
+      if (type == 1) { return 1; }
+      type = 0;
+      temp++;
+      continue;
+    }
+
+    if ((temp[0] == '.') && (type < 2))
+      type = 1;
+    if (temp[0] != '.')
+      type = 2;
+
+    temp++;
+  } /* while */
+
+  return (type == 1);
+}
+
 /* Local Variables: */
 /* mode:c */
 /* tab-width:4 */

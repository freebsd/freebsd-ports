--- src/xsane-back-gtk.c.tmpfile	Wed Nov 21 18:43:20 2001
+++ src/xsane-back-gtk.c	Wed Nov 21 18:57:22 2001
@@ -319,7 +319,6 @@
   {
    char tmpbuf[256];
    uid_t uid;
-   int rnd;
 
     uid = getuid();
     snprintf(tmpbuf, sizeof(tmpbuf), "%d-", uid);
@@ -341,12 +340,6 @@
     memcpy(buf + len, "XXXXXX", 6);		/* create unique filename */
     len += 6;
     buf[len] = '\0';
-    memcpy(buf, mktemp(buf), len);
-
-    rnd = random() & 65535;			/* add random number */
-    snprintf(tmpbuf, sizeof(tmpbuf), "%05d-", rnd);
-    memcpy(buf+len, tmpbuf, strlen(tmpbuf));
-    len += 6;
   }
 
   if (dev_name)
@@ -410,6 +403,13 @@
 
   buf[len++] = '\0';
 
+  {
+    int fd = mkstemp (buf);
+    if (fd == -1)
+      return -1;
+    close (fd);
+  }
+
   DBG(DBG_proc, "path = \"%s\"\n", buf);
 
   return 0;

--- link.c.orig	2016-11-29 15:11:31 UTC
+++ link.c
@@ -511,8 +511,8 @@ static void pdfinfo (void)
         { "info:Producer", "Producer" },
         { "info:CreationDate", "Creation date" },
     };
-    int len = 256;
-    char *buf = malloc (len);
+    int len = 0;
+    char *buf = NULL;
 
     for (size_t i = 0; i < sizeof (metatbl) / sizeof (metatbl[1]); ++i) {
         int need;
@@ -524,9 +524,9 @@ static void pdfinfo (void)
                 printd ("info %s\t%s", metatbl[i].name, buf);
             }
             else {
-                buf = realloc (buf, need);
-                if (!buf) err (1, "realloc %d", need);
-                len = need;
+                buf = realloc (buf, need + 1);
+                if (!buf) err (1, "realloc %d", need + 1);
+                len = need + 1;
                 goto again;
             }
         }
@@ -1670,7 +1670,6 @@ static void * mainloop (void UNUSED_ATTR
             }
 
             lock ("open");
-            fz_set_use_document_css (state.ctx, usedoccss);
             fz_try (state.ctx) {
                 ok = openxref (filename, password);
             }
@@ -4008,8 +4007,7 @@ CAMLprim value ml_platform (value unit_v
     platid = pilinux;
 #elif defined __CYGWIN__
     platid = picygwin;
-#elif defined __DragonFly__ || defined __FreeBSD__
-    || defined __OpenBSD__ || defined __NetBSD__
+#elif defined __DragonFly__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
     platid = pibsd;
 #elif defined __sun__
     platid = pisun;

--- FileNom.c.orig
+++ FileNom.c
@@ -377,6 +377,13 @@ ClassInitialize()
     CLASS(selectTranslations) = XtParseTranslationTable(selectTranslations);
 }
 
+#if defined(SYSV) || defined(__linux__) || defined(__FreeBSD__)
+    extern char *getcwd();
+#define getwd(buf) getcwd(buf,MAXPATHLEN)
+#else
+    extern char *getwd();
+#endif
+
 /* ARGSUSED */
 static void
 Initialize(req, new, args, num_args)
@@ -391,13 +398,6 @@ Initialize(req, new, args, num_args)
     String dir, menuList, p, q;
     Dimension width, height;
 
-#ifdef SYSV
-    extern char *getcwd();
-#define getwd(buf) getcwd(buf,MAXPATHLEN)
-#else
-    extern char *getwd();
-#endif
-
     List(new) = NULL;
     Nomination(new).directoryPart = NULL;
     Nomination(new).filenamePart = NULL;

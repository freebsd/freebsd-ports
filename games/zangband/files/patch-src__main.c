--- src/main.c.orig
+++ src/main.c
@@ -25,6 +25,10 @@
  */
 static const module_type modules[] =
 {
+#ifdef USE_GCU
+	INIT_MODULE(gcu),
+#endif /* USE_GCU */
+
 #ifdef USE_GTK
 	INIT_MODULE(gtk),
 #endif /* USE_GTK */
@@ -45,10 +49,6 @@
 	INIT_MODULE(tnb),
 #endif /* USE_TNB */
 
-#ifdef USE_GCU
-	INIT_MODULE(gcu),
-#endif /* USE_GCU */
-
 #ifdef USE_CAP
 	INIT_MODULE(cap),
 #endif /* USE_CAP */

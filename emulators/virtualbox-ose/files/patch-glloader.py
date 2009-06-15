Index: src/VBox/GuestHost/OpenGL/spu_loader/glloader.py
@@ -149,7 +149,7 @@
 		}*/
 #endif
 	}
-#if !defined(__linux__) && !defined(SunOS)
+#if !defined(__linux__) && !defined(SunOS) && !defined(__FreeBSD__)
 	crStrcat( system_path, "/" );
 #endif
 	crStrcat( system_path, lib );

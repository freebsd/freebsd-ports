Recommended in https://github.com/scottdraves/electricsheep/issues/72#issuecomment-455900619
--- DisplayOutput/OpenGL/glx.cpp.orig	2019-01-20 21:32:07 UTC
+++ DisplayOutput/OpenGL/glx.cpp
@@ -466,13 +466,13 @@ void CUnixGL::toggleVSync()
 {
     m_VSync = !m_VSync;
 
-    if( GLEE_GLX_SGI_swap_control )
-    {
-        if( m_VSync )
-            glXSwapIntervalSGI(1);
-        else
-            glXSwapIntervalSGI(2);
-    }
+    //if( GLEE_GLX_SGI_swap_control )
+    //{
+    //    if( m_VSync )
+    //        glXSwapIntervalSGI(1);
+    //    else
+    //        glXSwapIntervalSGI(2);
+    //}
 }
 
 /*


$FreeBSD$

--- src/theme.cc.orig	Tue Aug 13 21:56:19 2002
+++ src/theme.cc	Tue Aug 13 21:56:46 2002
@@ -123,11 +123,11 @@
     /*
      * Make sure there's no directory traversal in the theme name.
      */
-    if ( m_theme.find( ".." ) != (unsigned int)-1 )
+    if ( m_theme.find( ".." ) != std::string::npos )
     {
 	return 0;
     }
-    if ( m_theme.find( "/" ) != (unsigned int)-1 )
+    if ( m_theme.find( "/" ) != std::string::npos )
     {
 	return 0;
     }

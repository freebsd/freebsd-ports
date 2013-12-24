--- SWIG/KikiText.i.orig	2003-04-09 06:58:32.000000000 +0400
+++ SWIG/KikiText.i	2013-12-18 23:22:07.556750393 +0400
@@ -10,7 +10,7 @@
                         KikiText	( const std::string & = "", bool center = true, int colorIndex = 0 );
     
     void		setText		( const std::string & str, int colorIndex = base_color );
-    const std::string &	getText		() const;
+    std::string 	getText		() const;
     
     void		clear		();
     bool		isEmpty		() const;

SpiralLoops.C:196: assignment to `char *' from `const char *' discards qualifiers

--- SpiralLoops.h.orig	Sun Nov 26 07:53:44 2000
+++ SpiralLoops.h	Wed Dec  6 21:55:54 2000
@@ -85,7 +85,7 @@
     short *(*Run)(void);
     void   (*Destroy)(void);
     void    *handle;
-    char    *error;
+    const char  *error;
 	short   *m_PluginBuffer;
 	bool	 m_PluginOpen;
 	bool	 m_PluginLinked;

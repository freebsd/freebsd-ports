--- AstroMenaceSource/Core/RendererInterface/RendererInterface.h.orig	2012-08-25 13:33:11.000000000 +0400
+++ AstroMenaceSource/Core/RendererInterface/RendererInterface.h	2012-08-25 13:36:09.000000000 +0400
@@ -37,7 +37,7 @@
 #include "../Base.h"
 #include "../Math/Math.h"
 #include "../Texture/Texture.h"
-
+#define PFNGLCLIENTACTIVETEXTUREPROC PFNGLACTIVETEXTUREPROC
 
 
 struct eDevCaps

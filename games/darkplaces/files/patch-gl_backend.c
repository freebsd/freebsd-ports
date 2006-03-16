--- gl_backend.c.orig	Fri May 20 00:24:12 2005
+++ gl_backend.c	Sun Jan 15 17:06:32 2006
@@ -21,6 +21,8 @@
 cvar_t gl_dither = {CVAR_SAVE, "gl_dither", "1"}; // whether or not to use dithering
 cvar_t gl_lockarrays = {0, "gl_lockarrays", "1"};
 
+cvar_t gl_compilelogs = {0, "gl_compilelogs", "0"};
+
 int gl_maxdrawrangeelementsvertices;
 int gl_maxdrawrangeelementsindices;
 
@@ -236,6 +238,7 @@
 	Cvar_RegisterVariable(&gl_polyblend);
 	Cvar_RegisterVariable(&gl_dither);
 	Cvar_RegisterVariable(&gl_lockarrays);
+	Cvar_RegisterVariable(&gl_compilelogs);
 	Cvar_RegisterVariable(&gl_paranoid);
 	Cvar_RegisterVariable(&gl_printcheckerror);
 #ifdef NORENDER
@@ -780,7 +783,7 @@
 		CHECKGLERROR
 		qglGetObjectParameterivARB(vertexshaderobject, GL_OBJECT_COMPILE_STATUS_ARB, &vertexshadercompiled);
 		qglGetInfoLogARB(vertexshaderobject, sizeof(compilelog), NULL, compilelog);
-		if (compilelog[0])
+		if (gl_compilelogs.integer && compilelog[0])
 			Con_Printf("vertex shader compile log:\n%s\n", compilelog);
 		if (!vertexshadercompiled)
 		{
@@ -809,7 +812,7 @@
 		CHECKGLERROR
 		qglGetObjectParameterivARB(fragmentshaderobject, GL_OBJECT_COMPILE_STATUS_ARB, &fragmentshadercompiled);
 		qglGetInfoLogARB(fragmentshaderobject, sizeof(compilelog), NULL, compilelog);
-		if (compilelog[0])
+		if (gl_compilelogs.integer && compilelog[0])
 			Con_Printf("fragment shader compile log:\n%s\n", compilelog);
 		if (!fragmentshadercompiled)
 		{
@@ -827,7 +830,7 @@
 	CHECKGLERROR
 	qglGetObjectParameterivARB(programobject, GL_OBJECT_LINK_STATUS_ARB, &programlinked);
 	qglGetInfoLogARB(programobject, sizeof(compilelog), NULL, compilelog);
-	if (compilelog[0])
+	if (gl_compilelogs.integer && compilelog[0])
 	{
 		Con_Printf("program link log:\n%s\n", compilelog);
 		// software vertex shader is ok but software fragment shader is WAY

--- c_src/esdl_glext.c.orig	Fri Mar 14 18:29:43 2003
+++ c_src/esdl_glext.c	Fri May  9 08:13:18 2003
@@ -1987,7 +1987,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
+//typedef void (APIENTRY * PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
 PFNGLBLENDFUNCSEPARATEPROC esdl_glBlendFuncSeparate = NULL;
 void egl_blendFuncSeparate(sdl_data *, int, char *);
 sdl_fun esdl_load_glBlendFuncSeparate()
@@ -2014,7 +2014,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLFOGCOORDFPROC)(GLfloat coord);
+//typedef void (APIENTRY * PFNGLFOGCOORDFPROC)(GLfloat coord);
 PFNGLFOGCOORDFPROC esdl_glFogCoordf = NULL;
 void egl_fogCoordf(sdl_data *, int, char *);
 sdl_fun esdl_load_glFogCoordf()
@@ -2035,7 +2035,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLFOGCOORDFVPROC)( const GLfloat * coord);
+//typedef void (APIENTRY * PFNGLFOGCOORDFVPROC)( const GLfloat * coord);
 PFNGLFOGCOORDFVPROC esdl_glFogCoordfv = NULL;
 void egl_fogCoordfv(sdl_data *, int, char *);
 sdl_fun esdl_load_glFogCoordfv()
@@ -2056,7 +2056,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLFOGCOORDDPROC)(GLdouble coord);
+//typedef void (APIENTRY * PFNGLFOGCOORDDPROC)(GLdouble coord);
 PFNGLFOGCOORDDPROC esdl_glFogCoordd = NULL;
 void egl_fogCoordd(sdl_data *, int, char *);
 sdl_fun esdl_load_glFogCoordd()
@@ -2077,7 +2077,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLFOGCOORDDVPROC)( const GLdouble * coord);
+//typedef void (APIENTRY * PFNGLFOGCOORDDVPROC)( const GLdouble * coord);
 PFNGLFOGCOORDDVPROC esdl_glFogCoorddv = NULL;
 void egl_fogCoorddv(sdl_data *, int, char *);
 sdl_fun esdl_load_glFogCoorddv()
@@ -2098,7 +2098,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride,  const GLvoid * pointer);
+//typedef void (APIENTRY * PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride,  const GLvoid * pointer);
 PFNGLFOGCOORDPOINTERPROC esdl_glFogCoordPointer = NULL;
 void egl_fogCoordPointer(sdl_data *, int, char *);
 sdl_fun esdl_load_glFogCoordPointer()
@@ -2130,7 +2130,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLMULTIDRAWARRAYSPROC)(GLenum mode,  const GLint * first,  const GLsizei * count, GLsizei primcount);
+//typedef void (APIENTRY * PFNGLMULTIDRAWARRAYSPROC)(GLenum mode,  const GLint * first,  const GLsizei * count, GLsizei primcount);
 PFNGLMULTIDRAWARRAYSPROC esdl_glMultiDrawArrays = NULL;
 void egl_multiDrawArrays(sdl_data *, int, char *);
 sdl_fun esdl_load_glMultiDrawArrays()
@@ -2159,7 +2159,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
+//typedef void (APIENTRY * PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
 PFNGLPOINTPARAMETERFPROC esdl_glPointParameterf = NULL;
 void egl_pointParameterf(sdl_data *, int, char *);
 sdl_fun esdl_load_glPointParameterf()
@@ -2182,7 +2182,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPOINTPARAMETERFVPROC)(GLenum pname,  const GLfloat * params);
+//typedef void (APIENTRY * PFNGLPOINTPARAMETERFVPROC)(GLenum pname,  const GLfloat * params);
 PFNGLPOINTPARAMETERFVPROC esdl_glPointParameterfv = NULL;
 void egl_pointParameterfv(sdl_data *, int, char *);
 sdl_fun esdl_load_glPointParameterfv()
@@ -2205,7 +2205,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
+//typedef void (APIENTRY * PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
 PFNGLPOINTPARAMETERIPROC esdl_glPointParameteri = NULL;
 void egl_pointParameteri(sdl_data *, int, char *);
 sdl_fun esdl_load_glPointParameteri()
@@ -2228,7 +2228,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPOINTPARAMETERIVPROC)(GLenum pname,  const GLint * params);
+//typedef void (APIENTRY * PFNGLPOINTPARAMETERIVPROC)(GLenum pname,  const GLint * params);
 PFNGLPOINTPARAMETERIVPROC esdl_glPointParameteriv = NULL;
 void egl_pointParameteriv(sdl_data *, int, char *);
 sdl_fun esdl_load_glPointParameteriv()
@@ -2251,7 +2251,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3BVPROC)( const GLbyte * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3BVPROC)( const GLbyte * v);
 PFNGLSECONDARYCOLOR3BVPROC esdl_glSecondaryColor3bv = NULL;
 void egl_secondaryColor3bv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3bv()
@@ -2272,7 +2272,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3DVPROC)( const GLdouble * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3DVPROC)( const GLdouble * v);
 PFNGLSECONDARYCOLOR3DVPROC esdl_glSecondaryColor3dv = NULL;
 void egl_secondaryColor3dv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3dv()
@@ -2293,7 +2293,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3FVPROC)( const GLfloat * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3FVPROC)( const GLfloat * v);
 PFNGLSECONDARYCOLOR3FVPROC esdl_glSecondaryColor3fv = NULL;
 void egl_secondaryColor3fv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3fv()
@@ -2314,7 +2314,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3IVPROC)( const GLint * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3IVPROC)( const GLint * v);
 PFNGLSECONDARYCOLOR3IVPROC esdl_glSecondaryColor3iv = NULL;
 void egl_secondaryColor3iv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3iv()
@@ -2335,7 +2335,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3SVPROC)( const GLshort * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3SVPROC)( const GLshort * v);
 PFNGLSECONDARYCOLOR3SVPROC esdl_glSecondaryColor3sv = NULL;
 void egl_secondaryColor3sv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3sv()
@@ -2356,7 +2356,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UBVPROC)( const GLubyte * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UBVPROC)( const GLubyte * v);
 PFNGLSECONDARYCOLOR3UBVPROC esdl_glSecondaryColor3ubv = NULL;
 void egl_secondaryColor3ubv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3ubv()
@@ -2377,7 +2377,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UIVPROC)( const GLuint * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UIVPROC)( const GLuint * v);
 PFNGLSECONDARYCOLOR3UIVPROC esdl_glSecondaryColor3uiv = NULL;
 void egl_secondaryColor3uiv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3uiv()
@@ -2398,7 +2398,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLOR3USVPROC)( const GLushort * v);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLOR3USVPROC)( const GLushort * v);
 PFNGLSECONDARYCOLOR3USVPROC esdl_glSecondaryColor3usv = NULL;
 void egl_secondaryColor3usv(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColor3usv()
@@ -2419,7 +2419,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride,  const GLvoid * pointer);
+//typedef void (APIENTRY * PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride,  const GLvoid * pointer);
 PFNGLSECONDARYCOLORPOINTERPROC esdl_glSecondaryColorPointer = NULL;
 void egl_secondaryColorPointer(sdl_data *, int, char *);
 sdl_fun esdl_load_glSecondaryColorPointer()
@@ -2453,7 +2453,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS2DVPROC)( const GLdouble * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS2DVPROC)( const GLdouble * v);
 PFNGLWINDOWPOS2DVPROC esdl_glWindowPos2dv = NULL;
 void egl_windowPos2dv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos2dv()
@@ -2474,7 +2474,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS2FVPROC)( const GLfloat * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS2FVPROC)( const GLfloat * v);
 PFNGLWINDOWPOS2FVPROC esdl_glWindowPos2fv = NULL;
 void egl_windowPos2fv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos2fv()
@@ -2495,7 +2495,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS2IVPROC)( const GLint * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS2IVPROC)( const GLint * v);
 PFNGLWINDOWPOS2IVPROC esdl_glWindowPos2iv = NULL;
 void egl_windowPos2iv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos2iv()
@@ -2516,7 +2516,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS2SVPROC)( const GLshort * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS2SVPROC)( const GLshort * v);
 PFNGLWINDOWPOS2SVPROC esdl_glWindowPos2sv = NULL;
 void egl_windowPos2sv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos2sv()
@@ -2537,7 +2537,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS3DVPROC)( const GLdouble * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS3DVPROC)( const GLdouble * v);
 PFNGLWINDOWPOS3DVPROC esdl_glWindowPos3dv = NULL;
 void egl_windowPos3dv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos3dv()
@@ -2558,7 +2558,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS3FVPROC)( const GLfloat * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS3FVPROC)( const GLfloat * v);
 PFNGLWINDOWPOS3FVPROC esdl_glWindowPos3fv = NULL;
 void egl_windowPos3fv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos3fv()
@@ -2579,7 +2579,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS3IVPROC)( const GLint * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS3IVPROC)( const GLint * v);
 PFNGLWINDOWPOS3IVPROC esdl_glWindowPos3iv = NULL;
 void egl_windowPos3iv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos3iv()
@@ -2600,7 +2600,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWINDOWPOS3SVPROC)( const GLshort * v);
+//typedef void (APIENTRY * PFNGLWINDOWPOS3SVPROC)( const GLshort * v);
 PFNGLWINDOWPOS3SVPROC esdl_glWindowPos3sv = NULL;
 void egl_windowPos3sv(sdl_data *, int, char *);
 sdl_fun esdl_load_glWindowPos3sv()
@@ -2621,7 +2621,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTBVARBPROC)(GLint size,  const GLbyte * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTBVARBPROC)(GLint size,  const GLbyte * weights);
 PFNGLWEIGHTBVARBPROC esdl_glWeightbvARB = NULL;
 void egl_weightbvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightbvARB()
@@ -2645,7 +2645,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTSVARBPROC)(GLint size,  const GLshort * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTSVARBPROC)(GLint size,  const GLshort * weights);
 PFNGLWEIGHTSVARBPROC esdl_glWeightsvARB = NULL;
 void egl_weightsvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightsvARB()
@@ -2669,7 +2669,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTIVARBPROC)(GLint size,  const GLint * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTIVARBPROC)(GLint size,  const GLint * weights);
 PFNGLWEIGHTIVARBPROC esdl_glWeightivARB = NULL;
 void egl_weightivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightivARB()
@@ -2693,7 +2693,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTFVARBPROC)(GLint size,  const GLfloat * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTFVARBPROC)(GLint size,  const GLfloat * weights);
 PFNGLWEIGHTFVARBPROC esdl_glWeightfvARB = NULL;
 void egl_weightfvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightfvARB()
@@ -2717,7 +2717,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTDVARBPROC)(GLint size,  const GLdouble * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTDVARBPROC)(GLint size,  const GLdouble * weights);
 PFNGLWEIGHTDVARBPROC esdl_glWeightdvARB = NULL;
 void egl_weightdvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightdvARB()
@@ -2744,7 +2744,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTUBVARBPROC)(GLint size,  const GLubyte * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTUBVARBPROC)(GLint size,  const GLubyte * weights);
 PFNGLWEIGHTUBVARBPROC esdl_glWeightubvARB = NULL;
 void egl_weightubvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightubvARB()
@@ -2768,7 +2768,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTUSVARBPROC)(GLint size,  const GLushort * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTUSVARBPROC)(GLint size,  const GLushort * weights);
 PFNGLWEIGHTUSVARBPROC esdl_glWeightusvARB = NULL;
 void egl_weightusvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightusvARB()
@@ -2792,7 +2792,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTUIVARBPROC)(GLint size,  const GLuint * weights);
+//typedef void (APIENTRY * PFNGLWEIGHTUIVARBPROC)(GLint size,  const GLuint * weights);
 PFNGLWEIGHTUIVARBPROC esdl_glWeightuivARB = NULL;
 void egl_weightuivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightuivARB()
@@ -2816,7 +2816,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLWEIGHTPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride,  const GLvoid * pointer);
+//typedef void (APIENTRY * PFNGLWEIGHTPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride,  const GLvoid * pointer);
 PFNGLWEIGHTPOINTERARBPROC esdl_glWeightPointerARB = NULL;
 void egl_weightPointerARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glWeightPointerARB()
@@ -2850,7 +2850,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXBLENDARBPROC)(GLint count);
+//typedef void (APIENTRY * PFNGLVERTEXBLENDARBPROC)(GLint count);
 PFNGLVERTEXBLENDARBPROC esdl_glVertexBlendARB = NULL;
 void egl_vertexBlendARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexBlendARB()
@@ -2871,7 +2871,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint index);
+//typedef void (APIENTRY * PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint index);
 PFNGLCURRENTPALETTEMATRIXARBPROC esdl_glCurrentPaletteMatrixARB = NULL;
 void egl_currentPaletteMatrixARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glCurrentPaletteMatrixARB()
@@ -2892,7 +2892,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLMATRIXINDEXUBVARBPROC)(GLint size,  const GLubyte * indices);
+//typedef void (APIENTRY * PFNGLMATRIXINDEXUBVARBPROC)(GLint size,  const GLubyte * indices);
 PFNGLMATRIXINDEXUBVARBPROC esdl_glMatrixIndexubvARB = NULL;
 void egl_matrixIndexubvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glMatrixIndexubvARB()
@@ -2916,7 +2916,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLMATRIXINDEXUSVARBPROC)(GLint size,  const GLushort * indices);
+//typedef void (APIENTRY * PFNGLMATRIXINDEXUSVARBPROC)(GLint size,  const GLushort * indices);
 PFNGLMATRIXINDEXUSVARBPROC esdl_glMatrixIndexusvARB = NULL;
 void egl_matrixIndexusvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glMatrixIndexusvARB()
@@ -2940,7 +2940,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLMATRIXINDEXUIVARBPROC)(GLint size,  const GLuint * indices);
+//typedef void (APIENTRY * PFNGLMATRIXINDEXUIVARBPROC)(GLint size,  const GLuint * indices);
 PFNGLMATRIXINDEXUIVARBPROC esdl_glMatrixIndexuivARB = NULL;
 void egl_matrixIndexuivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glMatrixIndexuivARB()
@@ -2964,7 +2964,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLMATRIXINDEXPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride,  const GLvoid * pointer);
+//typedef void (APIENTRY * PFNGLMATRIXINDEXPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride,  const GLvoid * pointer);
 PFNGLMATRIXINDEXPOINTERARBPROC esdl_glMatrixIndexPointerARB = NULL;
 void egl_matrixIndexPointerARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glMatrixIndexPointerARB()
@@ -2998,7 +2998,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB1DVARBPROC)(GLuint index,  const GLdouble * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB1DVARBPROC)(GLuint index,  const GLdouble * v);
 PFNGLVERTEXATTRIB1DVARBPROC esdl_glVertexAttrib1dvARB = NULL;
 void egl_vertexAttrib1dvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib1dvARB()
@@ -3021,7 +3021,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB1FVARBPROC)(GLuint index,  const GLfloat * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB1FVARBPROC)(GLuint index,  const GLfloat * v);
 PFNGLVERTEXATTRIB1FVARBPROC esdl_glVertexAttrib1fvARB = NULL;
 void egl_vertexAttrib1fvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib1fvARB()
@@ -3044,7 +3044,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB1SVARBPROC)(GLuint index,  const GLshort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB1SVARBPROC)(GLuint index,  const GLshort * v);
 PFNGLVERTEXATTRIB1SVARBPROC esdl_glVertexAttrib1svARB = NULL;
 void egl_vertexAttrib1svARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib1svARB()
@@ -3067,7 +3067,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB2DVARBPROC)(GLuint index,  const GLdouble * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB2DVARBPROC)(GLuint index,  const GLdouble * v);
 PFNGLVERTEXATTRIB2DVARBPROC esdl_glVertexAttrib2dvARB = NULL;
 void egl_vertexAttrib2dvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib2dvARB()
@@ -3090,7 +3090,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB2FVARBPROC)(GLuint index,  const GLfloat * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB2FVARBPROC)(GLuint index,  const GLfloat * v);
 PFNGLVERTEXATTRIB2FVARBPROC esdl_glVertexAttrib2fvARB = NULL;
 void egl_vertexAttrib2fvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib2fvARB()
@@ -3113,7 +3113,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB2SVARBPROC)(GLuint index,  const GLshort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB2SVARBPROC)(GLuint index,  const GLshort * v);
 PFNGLVERTEXATTRIB2SVARBPROC esdl_glVertexAttrib2svARB = NULL;
 void egl_vertexAttrib2svARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib2svARB()
@@ -3136,7 +3136,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB3DVARBPROC)(GLuint index,  const GLdouble * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB3DVARBPROC)(GLuint index,  const GLdouble * v);
 PFNGLVERTEXATTRIB3DVARBPROC esdl_glVertexAttrib3dvARB = NULL;
 void egl_vertexAttrib3dvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib3dvARB()
@@ -3159,7 +3159,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB3FVARBPROC)(GLuint index,  const GLfloat * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB3FVARBPROC)(GLuint index,  const GLfloat * v);
 PFNGLVERTEXATTRIB3FVARBPROC esdl_glVertexAttrib3fvARB = NULL;
 void egl_vertexAttrib3fvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib3fvARB()
@@ -3182,7 +3182,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB3SVARBPROC)(GLuint index,  const GLshort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB3SVARBPROC)(GLuint index,  const GLshort * v);
 PFNGLVERTEXATTRIB3SVARBPROC esdl_glVertexAttrib3svARB = NULL;
 void egl_vertexAttrib3svARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib3svARB()
@@ -3205,7 +3205,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint index,  const GLbyte * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint index,  const GLbyte * v);
 PFNGLVERTEXATTRIB4NBVARBPROC esdl_glVertexAttrib4NbvARB = NULL;
 void egl_vertexAttrib4NbvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NbvARB()
@@ -3228,7 +3228,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint index,  const GLint * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint index,  const GLint * v);
 PFNGLVERTEXATTRIB4NIVARBPROC esdl_glVertexAttrib4NivARB = NULL;
 void egl_vertexAttrib4NivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NivARB()
@@ -3251,7 +3251,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint index,  const GLshort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint index,  const GLshort * v);
 PFNGLVERTEXATTRIB4NSVARBPROC esdl_glVertexAttrib4NsvARB = NULL;
 void egl_vertexAttrib4NsvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NsvARB()
@@ -3274,7 +3274,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
 PFNGLVERTEXATTRIB4NUBARBPROC esdl_glVertexAttrib4NubARB = NULL;
 void egl_vertexAttrib4NubARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NubARB()
@@ -3303,7 +3303,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint index,  const GLubyte * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint index,  const GLubyte * v);
 PFNGLVERTEXATTRIB4NUBVARBPROC esdl_glVertexAttrib4NubvARB = NULL;
 void egl_vertexAttrib4NubvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NubvARB()
@@ -3326,7 +3326,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint index,  const GLuint * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint index,  const GLuint * v);
 PFNGLVERTEXATTRIB4NUIVARBPROC esdl_glVertexAttrib4NuivARB = NULL;
 void egl_vertexAttrib4NuivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NuivARB()
@@ -3349,7 +3349,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint index,  const GLushort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint index,  const GLushort * v);
 PFNGLVERTEXATTRIB4NUSVARBPROC esdl_glVertexAttrib4NusvARB = NULL;
 void egl_vertexAttrib4NusvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4NusvARB()
@@ -3372,7 +3372,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4BVARBPROC)(GLuint index,  const GLbyte * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4BVARBPROC)(GLuint index,  const GLbyte * v);
 PFNGLVERTEXATTRIB4BVARBPROC esdl_glVertexAttrib4bvARB = NULL;
 void egl_vertexAttrib4bvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4bvARB()
@@ -3395,7 +3395,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4DVARBPROC)(GLuint index,  const GLdouble * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4DVARBPROC)(GLuint index,  const GLdouble * v);
 PFNGLVERTEXATTRIB4DVARBPROC esdl_glVertexAttrib4dvARB = NULL;
 void egl_vertexAttrib4dvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4dvARB()
@@ -3418,7 +3418,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4FVARBPROC)(GLuint index,  const GLfloat * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4FVARBPROC)(GLuint index,  const GLfloat * v);
 PFNGLVERTEXATTRIB4FVARBPROC esdl_glVertexAttrib4fvARB = NULL;
 void egl_vertexAttrib4fvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4fvARB()
@@ -3441,7 +3441,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4IVARBPROC)(GLuint index,  const GLint * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4IVARBPROC)(GLuint index,  const GLint * v);
 PFNGLVERTEXATTRIB4IVARBPROC esdl_glVertexAttrib4ivARB = NULL;
 void egl_vertexAttrib4ivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4ivARB()
@@ -3464,7 +3464,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4SVARBPROC)(GLuint index,  const GLshort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4SVARBPROC)(GLuint index,  const GLshort * v);
 PFNGLVERTEXATTRIB4SVARBPROC esdl_glVertexAttrib4svARB = NULL;
 void egl_vertexAttrib4svARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4svARB()
@@ -3487,7 +3487,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint index,  const GLubyte * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint index,  const GLubyte * v);
 PFNGLVERTEXATTRIB4UBVARBPROC esdl_glVertexAttrib4ubvARB = NULL;
 void egl_vertexAttrib4ubvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4ubvARB()
@@ -3510,7 +3510,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint index,  const GLuint * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint index,  const GLuint * v);
 PFNGLVERTEXATTRIB4UIVARBPROC esdl_glVertexAttrib4uivARB = NULL;
 void egl_vertexAttrib4uivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4uivARB()
@@ -3533,7 +3533,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIB4USVARBPROC)(GLuint index,  const GLushort * v);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIB4USVARBPROC)(GLuint index,  const GLushort * v);
 PFNGLVERTEXATTRIB4USVARBPROC esdl_glVertexAttrib4usvARB = NULL;
 void egl_vertexAttrib4usvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttrib4usvARB()
@@ -3556,7 +3556,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,  const GLvoid * pointer);
+//typedef void (APIENTRY * PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,  const GLvoid * pointer);
 PFNGLVERTEXATTRIBPOINTERARBPROC esdl_glVertexAttribPointerARB = NULL;
 void egl_vertexAttribPointerARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glVertexAttribPointerARB()
@@ -3596,7 +3596,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
+//typedef void (APIENTRY * PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
 PFNGLENABLEVERTEXATTRIBARRAYARBPROC esdl_glEnableVertexAttribArrayARB = NULL;
 void egl_enableVertexAttribArrayARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glEnableVertexAttribArrayARB()
@@ -3617,7 +3617,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
+//typedef void (APIENTRY * PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
 PFNGLDISABLEVERTEXATTRIBARRAYARBPROC esdl_glDisableVertexAttribArrayARB = NULL;
 void egl_disableVertexAttribArrayARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glDisableVertexAttribArrayARB()
@@ -3638,7 +3638,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPROGRAMSTRINGARBPROC)(GLenum target, GLenum format, GLsizei len,  const GLvoid * string);
+//typedef void (APIENTRY * PFNGLPROGRAMSTRINGARBPROC)(GLenum target, GLenum format, GLsizei len,  const GLvoid * string);
 PFNGLPROGRAMSTRINGARBPROC esdl_glProgramStringARB = NULL;
 void egl_programStringARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glProgramStringARB()
@@ -3672,7 +3672,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLBINDPROGRAMARBPROC)(GLenum target, GLuint program);
+//typedef void (APIENTRY * PFNGLBINDPROGRAMARBPROC)(GLenum target, GLuint program);
 PFNGLBINDPROGRAMARBPROC esdl_glBindProgramARB = NULL;
 void egl_bindProgramARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glBindProgramARB()
@@ -3695,7 +3695,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLDELETEPROGRAMSARBPROC)(GLsizei n,  const GLuint * programs);
+//typedef void (APIENTRY * PFNGLDELETEPROGRAMSARBPROC)(GLsizei n,  const GLuint * programs);
 PFNGLDELETEPROGRAMSARBPROC esdl_glDeleteProgramsARB = NULL;
 void egl_deleteProgramsARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glDeleteProgramsARB()
@@ -3719,7 +3719,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGENPROGRAMSARBPROC)(GLsizei n, GLuint * programs);
+//typedef void (APIENTRY * PFNGLGENPROGRAMSARBPROC)(GLsizei n, GLuint * programs);
 PFNGLGENPROGRAMSARBPROC esdl_glGenProgramsARB = NULL;
 void egl_genProgramsARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGenProgramsARB()
@@ -3751,7 +3751,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum target, GLuint index,  const GLdouble * params);
+//typedef void (APIENTRY * PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum target, GLuint index,  const GLdouble * params);
 PFNGLPROGRAMENVPARAMETER4DVARBPROC esdl_glProgramEnvParameter4dvARB = NULL;
 void egl_programEnvParameter4dvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glProgramEnvParameter4dvARB()
@@ -3776,7 +3776,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum target, GLuint index,  const GLfloat * params);
+//typedef void (APIENTRY * PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum target, GLuint index,  const GLfloat * params);
 PFNGLPROGRAMENVPARAMETER4FVARBPROC esdl_glProgramEnvParameter4fvARB = NULL;
 void egl_programEnvParameter4fvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glProgramEnvParameter4fvARB()
@@ -3801,7 +3801,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum target, GLuint index,  const GLdouble * params);
+//typedef void (APIENTRY * PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum target, GLuint index,  const GLdouble * params);
 PFNGLPROGRAMLOCALPARAMETER4DVARBPROC esdl_glProgramLocalParameter4dvARB = NULL;
 void egl_programLocalParameter4dvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glProgramLocalParameter4dvARB()
@@ -3826,7 +3826,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum target, GLuint index,  const GLfloat * params);
+//typedef void (APIENTRY * PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum target, GLuint index,  const GLfloat * params);
 PFNGLPROGRAMLOCALPARAMETER4FVARBPROC esdl_glProgramLocalParameter4fvARB = NULL;
 void egl_programLocalParameter4fvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glProgramLocalParameter4fvARB()
@@ -3851,7 +3851,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble * params);
+//typedef void (APIENTRY * PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble * params);
 PFNGLGETPROGRAMENVPARAMETERDVARBPROC esdl_glGetProgramEnvParameterdvARB = NULL;
 void egl_getProgramEnvParameterdvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetProgramEnvParameterdvARB()
@@ -3882,7 +3882,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat * params);
+//typedef void (APIENTRY * PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat * params);
 PFNGLGETPROGRAMENVPARAMETERFVARBPROC esdl_glGetProgramEnvParameterfvARB = NULL;
 void egl_getProgramEnvParameterfvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetProgramEnvParameterfvARB()
@@ -3913,7 +3913,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble * params);
+//typedef void (APIENTRY * PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble * params);
 PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC esdl_glGetProgramLocalParameterdvARB = NULL;
 void egl_getProgramLocalParameterdvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetProgramLocalParameterdvARB()
@@ -3944,7 +3944,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat * params);
+//typedef void (APIENTRY * PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat * params);
 PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC esdl_glGetProgramLocalParameterfvARB = NULL;
 void egl_getProgramLocalParameterfvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetProgramLocalParameterfvARB()
@@ -3975,7 +3975,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETPROGRAMIVARBPROC)(GLenum target, GLenum pname, GLint * params);
+//typedef void (APIENTRY * PFNGLGETPROGRAMIVARBPROC)(GLenum target, GLenum pname, GLint * params);
 PFNGLGETPROGRAMIVARBPROC esdl_glGetProgramivARB = NULL;
 void egl_getProgramivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetProgramivARB()
@@ -4005,7 +4005,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETPROGRAMSTRINGARBPROC)(GLenum target, GLenum pname, GLvoid * string);
+//typedef void (APIENTRY * PFNGLGETPROGRAMSTRINGARBPROC)(GLenum target, GLenum pname, GLvoid * string);
 PFNGLGETPROGRAMSTRINGARBPROC esdl_glGetProgramStringARB = NULL;
 void egl_getProgramStringARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetProgramStringARB()
@@ -4030,7 +4030,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint index, GLenum pname, GLdouble * params);
+//typedef void (APIENTRY * PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint index, GLenum pname, GLdouble * params);
 PFNGLGETVERTEXATTRIBDVARBPROC esdl_glGetVertexAttribdvARB = NULL;
 void egl_getVertexAttribdvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetVertexAttribdvARB()
@@ -4061,7 +4061,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint index, GLenum pname, GLfloat * params);
+//typedef void (APIENTRY * PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint index, GLenum pname, GLfloat * params);
 PFNGLGETVERTEXATTRIBFVARBPROC esdl_glGetVertexAttribfvARB = NULL;
 void egl_getVertexAttribfvARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetVertexAttribfvARB()
@@ -4092,7 +4092,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint index, GLenum pname, GLint * params);
+//typedef void (APIENTRY * PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint index, GLenum pname, GLint * params);
 PFNGLGETVERTEXATTRIBIVARBPROC esdl_glGetVertexAttribivARB = NULL;
 void egl_getVertexAttribivARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetVertexAttribivARB()
@@ -4123,7 +4123,7 @@
 
 }
 
-typedef void (APIENTRY * PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint index, GLenum pname,  GLvoid* *pointer);
+//typedef void (APIENTRY * PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint index, GLenum pname,  GLvoid* *pointer);
 PFNGLGETVERTEXATTRIBPOINTERVARBPROC esdl_glGetVertexAttribPointervARB = NULL;
 void egl_getVertexAttribPointervARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glGetVertexAttribPointervARB()
@@ -4154,7 +4154,7 @@
 
 }
 
-typedef GLboolean (APIENTRY * PFNGLISPROGRAMARBPROC)(GLuint program);
+//typedef GLboolean (APIENTRY * PFNGLISPROGRAMARBPROC)(GLuint program);
 PFNGLISPROGRAMARBPROC esdl_glIsProgramARB = NULL;
 void egl_isProgramARB(sdl_data *, int, char *);
 sdl_fun esdl_load_glIsProgramARB()

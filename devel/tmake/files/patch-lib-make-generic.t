--- lib/make/generic.t.orig	2004-02-29 18:20:44 UTC
+++ lib/make/generic.t
@@ -6,13 +6,13 @@
 
 ####### Compiler, tools and options
 
-CC	=	#$ Expand("TMAKE_CC");
-CXX	=	#$ Expand("TMAKE_CXX");
-CFLAGS	=	#$ Expand("TMAKE_CFLAGS"); 
-CXXFLAGS=	#$ Expand("TMAKE_CXXFLAGS");
+CC	?=	#$ Expand("TMAKE_CC");
+CXX	?=	#$ Expand("TMAKE_CXX");
+CFLAGS	+=	#$ Expand("TMAKE_CFLAGS"); 
+CXXFLAGS+=	#$ Expand("TMAKE_CXXFLAGS");
 INCPATH	=	#$ Expand('TMAKE_INCPATH');
 #$ Config("staticlib") && DisableOutput();
-LINK	=	#$ Expand("TMAKE_LINK");
+LINK	=	$(CXX)
 LFLAGS	=	#$ Expand("TMAKE_LFLAGS");
 LIBS	=	#$ Expand("TMAKE_LIBDIR_FLAGS"); Expand("TMAKE_LIBS");
 #$ Config("staticlib") && EnableOutput();

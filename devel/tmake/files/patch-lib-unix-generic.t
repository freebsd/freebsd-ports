--- lib/unix/generic.t.orig	2000-12-04 04:26:06.000000000 +0200
+++ lib/unix/generic.t	2010-08-27 22:54:27.797820407 +0300
@@ -205,13 +205,13 @@
 
 ####### Compiler, tools and options
 
-CC	=	#$ Expand("TMAKE_CC");
-CXX	=	#$ Expand("TMAKE_CXX");
-CFLAGS	=	#$ Expand("TMAKE_CFLAGS"); ExpandGlue("DEFINES","-D"," -D","");
-CXXFLAGS=	#$ Expand("TMAKE_CXXFLAGS"); ExpandGlue("DEFINES","-D"," -D","");
+CC	?=	#$ Expand("TMAKE_CC");
+CXX	?=	#$ Expand("TMAKE_CXX");
+CFLAGS	+=	#$ Expand("TMAKE_CFLAGS"); ExpandGlue("DEFINES","-D"," -D","");
+CXXFLAGS+=	#$ Expand("TMAKE_CXXFLAGS"); ExpandGlue("DEFINES","-D"," -D","");
 INCPATH	=	#$ ExpandPath("INCPATH","-I"," -I","");
 #$ Config("staticlib") && DisableOutput();
-LINK	=	#$ Expand("TMAKE_LINK");
+LINK	=	$(CXX)
 LFLAGS	=	#$ Expand("TMAKE_LFLAGS");
 LIBS	=	$(SUBLIBS) #$ Expand("TMAKE_LIBDIR_FLAGS"); Expand("TMAKE_LIBS");
 #$ Config("staticlib") && EnableOutput();

--- ./solenv/gbuild/platform/unxgcc.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./solenv/gbuild/platform/unxgcc.mk	2012-04-16 14:24:48.000000000 +0200
@@ -103,7 +103,7 @@
 ifeq ($(HAVE_CXX0X),TRUE)
 #Currently, as well as for its own merits, c++11/c++0x mode allows use to use
 #a template for SAL_N_ELEMENTS to detect at compiler time its misuse
-gb_CXXFLAGS += -std=c++0x
+gb_CXXFLAGS += -std=gnu++0x
 
 #We have so many std::auto_ptr uses that we need to be able to disable
 #warnings for those so that -Werror continues to be useful, seeing as moving

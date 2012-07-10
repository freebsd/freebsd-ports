--- ./solenv/gbuild/platform/unxgcc.mk.orig	2012-05-22 08:48:18.000000000 -0400
+++ ./solenv/gbuild/platform/unxgcc.mk	2012-07-10 18:27:15.000000000 -0400
@@ -58,10 +58,10 @@
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
 	-Wsign-promo \
 	-Woverloaded-virtual \
 	-Wno-non-virtual-dtor \
+	-Wno-unused-parameter \
 
 ifeq ($(HAVE_GCC_VISIBILITY_FEATURE),TRUE)
 gb_COMPILERDEFS += \
@@ -103,7 +103,7 @@
 ifeq ($(HAVE_CXX0X),TRUE)
 #Currently, as well as for its own merits, c++11/c++0x mode allows use to use
 #a template for SAL_N_ELEMENTS to detect at compiler time its misuse
-gb_CXXFLAGS += -std=c++0x
+gb_CXXFLAGS += -std=gnu++0x
 
 #We have so many std::auto_ptr uses that we need to be able to disable
 #warnings for those so that -Werror continues to be useful, seeing as moving

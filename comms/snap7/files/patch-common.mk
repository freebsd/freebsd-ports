--- common.mk.orig	2014-04-16 08:16:20 UTC
+++ common.mk
@@ -22,7 +22,9 @@ LinkOptions            :=  -O3
 IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../../src/sys $(IncludeSwitch)../../src/core $(IncludeSwitch)../../src/lib 
 Libs                   := $(LibrarySwitch)pthread $(LibrarySwitch)rt 
 LibPath                := $(LibraryPathSwitch). 
-LibInstall             := /usr/lib
+LibInstall             := $(DESTDIR)/$(PREFIX)/lib
+IncInstall             := $(DESTDIR)/$(PREFIX)/include
+WrapperInstall         := $(DESTDIR)/$(PREFIX)/share/examples/snap7/c-cpp
 
 ##
 ## Common variables (CXXFLAGS varies across platforms)
@@ -108,4 +110,6 @@ clean:
 
 install: all
 	cp -f $(OutputFile) $(LibInstall)
-
+	cp -f ../../release/Wrappers/c-cpp/snap7.h $(IncInstall)
+	$(MakeDirCommand) $(WrapperInstall)
+	cp -f ../../release/Wrappers/c-cpp/snap7.cpp $(WrapperInstall)

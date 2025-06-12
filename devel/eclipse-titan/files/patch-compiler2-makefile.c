--- compiler2/makefile.c.orig	2025-05-28 08:04:59 UTC
+++ compiler2/makefile.c
@@ -2130,7 +2130,7 @@ static void print_makefile(struct makefile_struct *mak
           "%s"
           "TTCN3_SUBDIR = \n"
           "ifndef TTCN3_DIR\n"
-          "TTCN3_DIR = %s\n"
+          "export TTCN3_DIR = %s\n"
           "endif\n"
       , titan_dir ?
         "# The value below points to the location of the TITAN version\n"
@@ -2169,7 +2169,7 @@ static void print_makefile(struct makefile_struct *mak
       }
       cxx_free = TRUE;
 #else
-      cxx = "g++";
+      cxx = CXX;
 #endif
     }
 
@@ -2295,6 +2295,11 @@ static void print_makefile(struct makefile_struct *mak
           "\n\n"
           "# Flags for the linker:\n"
           "LDFLAGS = %s%s %s\n\n"
+          "ifeq ($(PLATFORM), FREEBSD)\n"
+          "# Add -rpath for libgcc_s.so not to use one in the base system\n"
+          "LIBGCC_SO_DIR != dirname $$($(CXX) -print-file-name=libgcc_s.so)\n"
+          "LDFLAGS += -Wl,-rpath=$(LIBGCC_SO_DIR)\n"
+          "endif\n\n"
           "ifeq ($(PLATFORM), WIN32)\n"
           "# Silence linker warnings.\n"
           "LDFLAGS += -Wl,--enable-auto-import,--enable-runtime-pseudo-reloc\n"
@@ -2315,7 +2320,11 @@ static void print_makefile(struct makefile_struct *mak
           "OPENSSL_LIB_DIR = lib\n\n"
           "# The path of your libxml2 installation:\n"
           "# If you do not have your own one, leave it unchanged.\n"
+#ifdef XMLDIR
+          "%sXMLDIR = " XMLDIR "\n\n"
+#else
           "%sXMLDIR = $(TTCN3_DIR)\n\n"
+#endif
           "# Directory to store the archived source files:\n",
           makefile->dynamic ? "-Wall -fPIC" : "-Wall", /* CXXFLAGS */
           makefile->coverage ? " -fprofile-arcs -ftest-coverage -g" : "", /* CXXFLAGS COVERAGE */

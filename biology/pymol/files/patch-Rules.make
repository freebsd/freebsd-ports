--- Rules.make.orig	Wed Mar 23 10:53:37 2005
+++ Rules.make	Wed Mar 23 10:54:06 2005
@@ -4,27 +4,27 @@
 #
 #- Building ----------------------------------------------------------
 #--- Tell "make" how to get to PyMOL 
-PYMOL_PATH = ${HOME}/pymol
+PYMOL_PATH = @LOCALBASE@
 #---------------------------------------------------------------------
 #
 #- Dependencies ------------------------------------------------------
 #--- X-windows
-XLIB_DIR = -L/usr/X11R6/lib
-XINC_DIR = -I/usr/X11R6/include
+XLIB_DIR = -L@X11BASE@/lib
+XINC_DIR = -I@X11BASE@/include
 #--- Python
-PYTHON_EXE = $(PYMOL_PATH)/ext/bin/python
+PYTHON_EXE = $(PYMOL_PATH)/bin/python
 PYTHON_LIB =
 PYTHON_LIB_DIR = 
-PYTHON_INC_DIR = -I$(PYMOL_PATH)/ext/include/python2.3 \
-	-I$(PYMOL_PATH)/ext/include/python2.3/Numeric
+PYTHON_INC_DIR = -I$(PYMOL_PATH)/include/@PYTHON_VERSION@ \
+	-I$(PYMOL_PATH)/include/@PYTHON_VERSION@/Numeric
 #--- Other external dependencies
-EXT_INC_DIR = -I$(PYMOL_PATH)/ext/include
-EXT_LIB_DIR = -L$(PYMOL_PATH)/ext/lib
+EXT_INC_DIR = -I$(PYMOL_PATH)/include
+EXT_LIB_DIR = -L$(PYMOL_PATH)/lib
 #---------------------------------------------------------------------
 #
 #- Build for LINUX as an importable module ---------------------------
 #--- System libraries
-LIBS = $(PYTHON_LIB) -lglut -lGL -lGLU -ldl -lpng -lXmu $(ZLIB) -lm
+LIBS = $(PYTHON_LIB) -lglut -lGL -lGLU -lpng -lXmu $(ZLIB) -lm
 #--- PyMOL configuration
 DEFS = -D_PYMOL_MODULE -D_PYMOL_NUMPY -D_PYMOL_INLINE
 #--- How we build shared libraries
@@ -32,19 +32,19 @@
 #--- What are we trying to build?
 DEST = -o modules/pymol/_cmd.so
 #--- Gcc Options for Linux
-CCOPT1 = -march=i486 -D__i686__ -ffast-math -Wall -ansi -Wmissing-prototypes
+CCOPT1 = @CFLAGS@ #-march=i486 -D__i686__ -ffast-math -Wall -ansi -Wmissing-prototypes
 #--- libraries for PyOpenGL 
 PYOGL_LIB =  -lglut -lGL -lGLU -lXmu -lXi
 #---------------------------------------------------------------------
 #
 #- Choose One --------------------------------------------------------
 #--- GCC Optimized
-CCOPT2 = -O3 -funroll-loops -fomit-frame-pointer -finline-limit=10000 
+#CCOPT2 = -O3 -funroll-loops -fomit-frame-pointer -finline-limit=10000 
 #--- GCC Profiling
 #CCOPT2 = -pg -O3 -funroll-loops
 #--- Debugging
 #CCOPT2 = -g -D_MemoryDebug_ON
-CCOPT2 = -g
+CCOPT2 = #-g
 #---------------------------------------------------------------------
 #
 #- Choose One --------------------------------------------------------
@@ -70,7 +70,7 @@
 # No changes normally required below here
 #---------------------------------------------------------------------
 
-CC = cc
+CC = @CC@
 
 LIB_DIRS = $(EXT_LIB_DIR) $(PYTHON_LIB_DIR) $(XLIB_DIR)
 
@@ -79,7 +79,7 @@
    -I../layer3 -I../layer4 -I../layer5 
 
 C_FLAGS = $(CCOPT1) $(CCOPT2) $(EXT_INC_DIR) $(PYTHON_INC_DIR) \
-   $(XINC_DIR) $(PNG) $(DEFS) $(BUGS)
+   $(XINC_DIR) $(PNG) $(DEFS) $(BUGS) @PICFLAG@
 
 CFLAGS = $(C_FLAGS)
 

--- contrib/Chaco/main/Gmsh_printf.cpp-xxx	2009-07-20 16:52:04.000000000 -0500
+++ contrib/Chaco/main/Gmsh_printf.cpp	2009-07-20 16:52:15.000000000 -0500
@@ -4,6 +4,7 @@
 // bugs and problems to <gmsh@geuz.org>.
 
 #include <cstring>
+#include <cstdio>
 #include "GmshMessage.h"
 
 // Overload the printf statements in Chaco to write using Msg::Direct in gmsh

The later chunks (using i2b) are compile fixes on aarch64 (presumably with
clang6 as well). Typical error message reads

    readConfig.cpp:407:54: error: non-constant-expression cannot be narrowed 
    from type 'int' to 'unsigned char' in initializer list [-Wc++11-narrowing]
        unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
                                   ^~~~~~~~
    readConfig.cpp:407:54: note: insert an explicit cast to silence this issue
        unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
                                   ^~~~~~~~
                                   static_cast<unsigned char>( )

Since it happens in a half-dozen places, introduce a trivial helper function.

--- src/readConfig.cpp.orig	2018-01-21 16:58:09 UTC
+++ src/readConfig.cpp
@@ -4,6 +4,7 @@
 #include <fstream>
 #include <sstream>
 #include <string>
+#include <clocale>
 using namespace std;
 
 #include "body.h"
@@ -20,6 +21,8 @@ using namespace std;
 static PlanetProperties *defaultProperties;
 static PlanetProperties *currentProperties;
 
+static inline unsigned char i2b( int x ) { return static_cast<unsigned int>(x) & 0xffU; }
+
 static void
 readConfig(const char *line, PlanetProperties *planetProperties[])
 {
@@ -49,7 +52,7 @@ readConfig(const char *line, PlanetPrope
             int r, g, b;
             if (sscanf(returnString, "%d,%d,%d", &r, &g, &b) == 3)
             {
-                unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
+                unsigned char color[3] = { i2b(r), i2b(g), i2b(b) };
                 currentProperties->ArcColor(color);
             }
             else
@@ -179,7 +182,7 @@ readConfig(const char *line, PlanetPrope
             int r, g, b;
             if (sscanf(returnString, "%d,%d,%d", &r, &g, &b) == 3)
             {
-                unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
+                unsigned char color[3] = { i2b(r), i2b(g), i2b(b) };
                 currentProperties->Color(color);
             }
             else
@@ -244,7 +247,7 @@ readConfig(const char *line, PlanetPrope
             int r, g, b;
             if (sscanf(returnString, "%d,%d,%d", &r, &g, &b) == 3)
             {
-                unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
+                unsigned char color[3] = { i2b(r), i2b(g), i2b(b) };
                 currentProperties->GridColor(color);
             }
             else
@@ -296,7 +299,7 @@ readConfig(const char *line, PlanetPrope
             int r, g, b;
             if (sscanf(returnString, "%d,%d,%d", &r, &g, &b) == 3)
             {
-                unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
+                unsigned char color[3] = { i2b(r), i2b(g), i2b(b) };
                 currentProperties->MarkerColor(color);
             }
             else
@@ -403,7 +406,7 @@ readConfig(const char *line, PlanetPrope
             int r, g, b;
             if (sscanf(returnString, "%d,%d,%d", &r, &g, &b) == 3)
             {
-                unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
+                unsigned char color[3] = { i2b(r), i2b(g), i2b(b) };
                 currentProperties->OrbitColor(color);
             }
             else
@@ -473,7 +476,7 @@ readConfig(const char *line, PlanetPrope
             int r, g, b;
             if (sscanf(returnString, "%d,%d,%d", &r, &g, &b) == 3)
             {
-                unsigned char color[3] = { r & 0xff, g & 0xff, b & 0xff };
+                unsigned char color[3] = { i2b(r), i2b(g), i2b(b) };
                 currentProperties->TextColor(color);
             }
             else

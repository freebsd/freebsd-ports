--- ./jdk/make/tools/freetypecheck/freetypecheck.c.orig	2016-12-29 23:30:31.000000000 -0500
+++ ./jdk/make/tools/freetypecheck/freetypecheck.c	2019-05-29 18:29:32.876811000 -0400
@@ -32,26 +32,65 @@
 #define QUOTEMACRO(x) QUOTEME(x)
 #define QUOTEME(x) #x
 
+int compare_versions(FT_Int req_major, FT_Int req_minor, FT_Int req_patch,
+                     FT_Int major, FT_Int minor, FT_Int patch) {
+    if (major > req_major) {
+        printf("Major version %d greater than required major version %d\n",
+               major, req_major);
+        return 0;
+    }
+    if (major < req_major) {
+        printf("Major version %d less than required major version %d\n",
+               major, req_major);
+        return -1;
+    }
+    printf("Major version %d equal to required major version %d\n",
+           major, req_major);
+    if (minor > req_minor) {
+        printf("Minor version %d greater than required minor version %d\n",
+               minor, req_minor);
+        return 0;
+    }
+    if (minor < req_minor) {
+        printf("Minor version %d less than required minor version %d\n",
+               minor, req_minor);
+        return -2;
+    }
+    printf("Minor version %d equal to required minor version %d\n",
+           minor, req_minor);
+    if (patch >= req_patch) {
+        printf("Patch version %d greater than or equal to required patch version %d\n",
+               patch, req_patch);
+        return 0;
+    }
+    printf("Patch version %d less than required patch version %d\n",
+           patch, req_patch);
+    return -3;
+}
+
 int main(int argc, char** argv) {
-   char v[50];
-   FT_Int major, minor, patch;
+   FT_Int major, minor, patch, req_major, req_minor, req_patch;
    FT_Library library;
-   sprintf(v, "%d.%d.%d", FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
 
-   printf("Required version of freetype: %s\n",
-       QUOTEMACRO(REQUIRED_FREETYPE_VERSION));
+   sscanf(QUOTEMACRO(REQUIRED_FREETYPE_VERSION),
+          "%d.%d.%d", &req_major, &req_minor, &req_patch);
+   printf("Required version of freetype: %d.%d.%d\n",
+          req_major, req_minor, req_patch);
 
-   printf("Detected freetype headers: %s\n", v);
-   if (strcmp(v, QUOTEMACRO(REQUIRED_FREETYPE_VERSION)) < 0) {
+   printf("Detected freetype headers: %d.%d.%d\n",
+          FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
+   if (compare_versions(req_major, req_minor, req_patch,
+                        FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH) < 0) {
        printf("Failed: headers are too old.\n");
    }
 
    FT_Init_FreeType(&library);
    FT_Library_Version(library, &major, &minor, &patch);
-   sprintf(v, "%d.%d.%d", major, minor, patch);
 
-   printf("Detected freetype library: %s\n", v);
-   if (strcmp(v, QUOTEMACRO(REQUIRED_FREETYPE_VERSION)) < 0) {
+   printf("Detected freetype library: %d.%d.%d\n",
+          major, minor, patch);
+   if (compare_versions(req_major, req_minor, req_patch,
+                        major, minor, patch) < 0) {
       printf("Failed: too old library.\n");
    }
 

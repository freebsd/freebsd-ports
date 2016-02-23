--- chkccomp.c.orig	2016-01-28 21:32:12 UTC
+++ chkccomp.c
@@ -1925,14 +1925,14 @@ void determineGetaddrlimit (FILE *versio
     int has_getrlimit;
 
   /* determineGetaddrlimit */
-    has_getrlimit = compileAndLinkOk("#include <stdio.h>\n#include <sys/resource.h>\n"
+    has_getrlimit = compileAndLinkOk("#include <stdio.h>\n#include <sys/types.h>\n#include <sys/resource.h>\n"
                                      "int main(int argc, char *argv[]){\n"
                                      "struct rlimit rlim;\n"
                                      "printf(\"%d\\n\", getrlimit(RLIMIT_STACK, &rlim) == 0);\n"
                                      "return 0;}\n") && doTest() == 1;
     fprintf(versionFile, "#define HAS_GETRLIMIT %d\n", has_getrlimit);
     if (has_getrlimit) {
-      if (assertCompAndLnk("#include <stdio.h>\n#include <sys/resource.h>\n"
+      if (assertCompAndLnk("#include <stdio.h>\n#include <sys/types.h>\n#include <sys/resource.h>\n"
                            "int main(int argc, char *argv[]){\n"
                            "struct rlimit rlim;\n"
                            "getrlimit(RLIMIT_STACK, &rlim);"
@@ -1943,7 +1943,7 @@ void determineGetaddrlimit (FILE *versio
                            "return 0;}\n")) {
         fprintf(versionFile, "#define SOFT_STACK_LIMIT %lu\n", (unsigned long) doTest() * 1024);
       } /* if */
-      if (assertCompAndLnk("#include <stdio.h>\n#include <sys/resource.h>\n"
+      if (assertCompAndLnk("#include <stdio.h>\n#include <sys/types.h>\n#include <sys/resource.h>\n"
                            "int main(int argc, char *argv[]){\n"
                            "struct rlimit rlim;\n"
                            "getrlimit(RLIMIT_STACK, &rlim);"

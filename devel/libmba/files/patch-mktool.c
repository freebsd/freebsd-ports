--- mktool.c~
+++ mktool.c
@@ -89,18 +89,18 @@ static const char *arg_array[32] = {
 		"lib%n.%1.%2.%3.dylib",
 		"lib%n.%1.%2.dylib",
 		"lib%n.dylib",
 		"darwin",
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__)
 		"gcc",
 		" -g",
 		" -Wall -W",
 		" -Wall -W -ansi -pedantic",
 		" -std=c99",
 		" -std=c89",
 		" -fpic",
 		" -fPIC",
-		" -Wl,-soname,lib%n.so.%1.%2",
+		" -Wl,-soname,lib%n.so.%1",
 		"",
 		" -shared",
 		" -Wl,-rpath,%s",
 		"lib%n.so.%1",

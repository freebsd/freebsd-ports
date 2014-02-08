--- mainsdl.cpp.orig
+++ mainsdl.cpp
@@ -322,13 +322,23 @@ int main(int argc, char *argv[])
 	for (i=0; (i < argc || argv[i] != NULL); i++) {
 		
 		if(strcmp(argv[i], "-double") == 0) {
+#if defined(__i386__)
 			fScreenSize = 2;
 			fBlitterMode = 3;
+#else
+			fprintf(stderr, "-double is not supported on this platform\n");
+			exit(1);
+#endif
 		}
 		
 		if(strcmp(argv[i], "-scanline") == 0) {
+#if defined(__i386__)
 			fScreenSize = 2;
 			fBlitterMode = 2;
+#else
+			fprintf(stderr, "-scanline is not supported on this platform\n");
+			exit(1);
+#endif
 		}
 		
 		if (strncmp(argv[i], "-h", 2) == 0) {

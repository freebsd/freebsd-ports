diff --git asedit.c asedit.c
index 3ec7e5a..a5b2b5e 100644
--- asedit.c
+++ asedit.c
@@ -556,7 +556,7 @@ int  main (argc, argv)
 	char *argv[];
 #else  /* ! _NO_PROTO */
 
-int main (unsigned int argc, char *argv[])
+int main (int argc, char *argv[])
 #endif
 {
 

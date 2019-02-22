--- sources/utils/converter/opcode/Opcode.h.orig	2018-09-02 12:42:44 UTC
+++ sources/utils/converter/opcode/Opcode.h
@@ -41,9 +41,17 @@
 // Preprocessor
 #ifndef ICE_NO_DLL
 	#ifdef OPCODE_EXPORTS
-		#define OPCODE_API __declspec(dllexport)
+		#ifdef __GNUC__
+			#define OPCODE_API __attribute__((visibility("default")))
+		#else
+			#define OPCODE_API __declspec(dllexport)
+		#endif
 	#else
-		#define OPCODE_API __declspec(dllimport)
+		#ifdef __GNUC__
+			#define OPCODE_API __attribute__((visibility("hidden")))
+		#else
+			#define OPCODE_API __declspec(dllimport)
+		#endif
 	#endif
 #else
 		#define OPCODE_API

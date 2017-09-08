--- src/external/angelscript/sdk/angelscript/source/as_callfunc_x86.cpp.orig	2017-08-02 20:09:54 UTC
+++ src/external/angelscript/sdk/angelscript/source/as_callfunc_x86.cpp
@@ -340,7 +340,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(args), asPWORD(paramSize), asPWORD(func)};
 
 	asm __volatile__(
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -385,7 +385,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -462,7 +462,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(obj), asPWORD(args), asPWORD(paramSize), asPWORD(func)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -508,7 +508,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -585,7 +585,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(obj), asPWORD(args), asPWORD(paramSize), asPWORD(func)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -631,7 +631,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -717,7 +717,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(obj), asPWORD(args), asPWORD(paramSize), asPWORD(func), asPWORD(retPtr)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -767,7 +767,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -849,7 +849,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(args), asPWORD(paramSize), asPWORD(func), asPWORD(retPtr)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -896,7 +896,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -980,7 +980,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(obj), asPWORD(args), asPWORD(paramSize), asPWORD(func), asPWORD(retPtr)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -1030,7 +1030,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -1102,7 +1102,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(args), asPWORD(paramSize), asPWORD(func)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -1145,7 +1145,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -1233,7 +1233,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(obj), asPWORD(args), asPWORD(paramSize), asPWORD(func)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -1285,7 +1285,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp            \n"
 		"popl  %%ebx            \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"
@@ -1380,7 +1380,7 @@ endcopy:
 	volatile asPWORD a[] = {asPWORD(obj), asPWORD(args), asPWORD(paramSize), asPWORD(func), asPWORD(retPtr)};
 
 	asm __volatile__ (
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// When compiled with optimizations the stack unwind doesn't work properly, 
 		// causing exceptions to crash the application. By adding this prologue
 		// and the epilogue below, the stack unwind works as it should. 
@@ -1445,7 +1445,7 @@ endcopy:
 		// Pop the alignment bytes
 		"popl  %%esp           \n"
 		"popl  %%ebx           \n"
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && !defined(__clang__)
 		// Epilogue
 		"movl %%ebp, %%esp         \n"
 		".cfi_def_cfa_register esp \n"

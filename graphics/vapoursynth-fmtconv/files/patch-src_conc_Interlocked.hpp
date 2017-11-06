https://github.com/EleonoreMizo/fmtconv/pull/9

--- src/conc/Interlocked.hpp.orig	2016-03-25 15:06:59 UTC
+++ src/conc/Interlocked.hpp
@@ -100,10 +100,6 @@ int32_t	Interlocked::cas (int32_t volatile &dest, int3
 		::LONG (comp)
 	));
 
-#elif defined (__linux__)
-
-	return (__sync_val_compare_and_swap (&dest, comp, excg));
-
 #elif defined (__APPLE__)
 
 	return (::OSAtomicCompareAndSwap32Barrier (
@@ -112,6 +108,10 @@ int32_t	Interlocked::cas (int32_t volatile &dest, int3
 		const_cast <int32_t *> (reinterpret_cast <int32_t volatile *> (&dest))
 	) ? comp : excg);
 
+#elif defined (__GNUC__)
+
+	return (__sync_val_compare_and_swap (&dest, comp, excg));
+
 #else
 
 	#error Unknown platform
@@ -214,10 +214,6 @@ int64_t	Interlocked::cas (int64_t volatile &dest, int6
 
 	return (old);
 
-#elif defined (__linux__)
-
-	return (__sync_val_compare_and_swap (&dest, comp, excg));
-
 #elif defined (__APPLE__)
 
 	return (::OSAtomicCompareAndSwap64Barrier (
@@ -226,6 +222,10 @@ int64_t	Interlocked::cas (int64_t volatile &dest, int6
 		const_cast <int64_t *> (reinterpret_cast <int64_t volatile *> (&dest))
 	) ? comp : excg);
 
+#elif defined (__GNUC__)
+
+	return (__sync_val_compare_and_swap (&dest, comp, excg));
+
 #else
 
 	#error Unknown platform
@@ -355,9 +355,13 @@ void	Interlocked::cas (Data128 &old, volatile Data128 
 
 	#endif
 
-#elif defined (__linux__)
+#elif defined (__GNUC__)
 
 	old = __sync_val_compare_and_swap (&dest, comp, excg);
+
+#else
+
+	#error Unknown platform
 
 #endif
 }

--- src/hotspot/share/runtime/arguments.cpp.orig	2023-01-15 10:13:55.469227000 -0800
+++ src/hotspot/share/runtime/arguments.cpp	2023-01-15 10:20:49.218102000 -0800
@@ -1557,6 +1557,10 @@
 // set_use_compressed_oops().
 void Arguments::set_use_compressed_klass_ptrs() {
 #ifdef _LP64
+#  if defined(__FreeBSD__) && defined(AARCH64)
+  FLAG_SET_DEFAULT(UseCompressedClassPointers, false);
+  FLAG_SET_ERGO(UseCompressedClassPointers, false);
+#  else
   // On some architectures, the use of UseCompressedClassPointers implies the use of
   // UseCompressedOops. The reason is that the rheap_base register of said platforms
   // is reused to perform some optimized spilling, in order to use rheap_base as a
@@ -1582,6 +1586,7 @@
       }
     }
   }
+#  endif // __FreeBSD__ && AARCH64
 #endif // _LP64
 }
 

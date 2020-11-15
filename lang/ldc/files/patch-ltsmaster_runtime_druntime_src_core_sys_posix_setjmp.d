--- ltsmaster/runtime/druntime/src/core/sys/posix/setjmp.d.orig	2020-11-14 19:34:19 UTC
+++ ltsmaster/runtime/druntime/src/core/sys/posix/setjmp.d
@@ -163,6 +163,12 @@ else version( FreeBSD )
         enum _JBLEN = 5;
         struct _jmp_buf { c_long[_JBLEN + 1] _jb; }
     }
+    else version( AArch64 )
+    {
+        enum _JBLEN = 31;
+        // __int128_t
+        struct _jmp_buf { long[2][_JBLEN + 1] _jb; };
+    }
     else
         static assert(0);
     alias _jmp_buf[1] jmp_buf;
@@ -250,6 +256,11 @@ else version( FreeBSD )
         enum _JB_SIGFLAG    = 5;
         struct _sigjmp_buf { c_long[_JBLEN + 1] _sjb; }
     }
+    else version( AArch64 )
+    {
+        // __int128_t
+        struct _sigjmp_buf { long[2][_JBLEN + 1] _jb; };
+    } 
     else
         static assert(0);
     alias _sigjmp_buf[1] sigjmp_buf;

--- ltsmaster/runtime/druntime/src/core/sys/posix/ucontext.d.orig	2020-11-14 19:35:48 UTC
+++ ltsmaster/runtime/druntime/src/core/sys/posix/ucontext.d
@@ -686,6 +686,38 @@ else version( FreeBSD )
             int[6]          mc_spare2;
         }
     }
+    else version( AArch64 )
+    {
+        alias __register_t = long;
+
+        struct gpregs
+        {
+            __register_t[30] gp_x;
+            __register_t     gp_lr;
+            __register_t     gp_sp;
+            __register_t     gp_elr;
+            uint             gp_spsr;
+            int              gp_pad;
+        }
+
+        struct fpregs
+        {
+            ulong[2][32]    fp_q; // __uint128_t
+            uint            fp_sr;
+            uint            fp_cr;
+            int             fp_flags;
+            int             fp_pad;
+        }
+
+        struct mcontext_t
+        {
+            gpregs          mc_gpregs;
+            fpregs          mc_fpregs;
+            int             mc_flags;
+            int             mc_pad;
+            ulong[8]        mc_spare;
+        }
+    }
 
     // <ucontext.h>
     enum UCF_SWAPPED = 0x00000001;

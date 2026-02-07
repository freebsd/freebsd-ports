--- KQueue.xs.orig	2009-09-29 10:42:31.000000000 +0200
+++ KQueue.xs	2009-09-29 10:44:43.000000000 +0200
@@ -107,7 +107,8 @@ kevent(kq, timeout=&PL_sv_undef)
         av_push(array, newSViv(ke[i].flags));
         av_push(array, newSViv(ke[i].fflags));
         av_push(array, newSViv(ke[i].data));
-        av_push(array, SvREFCNT_inc(ke[i].udata));
+        if (ke[i].udata)
+            av_push(array, SvREFCNT_inc(ke[i].udata));
         PUSHs(sv_2mortal(newRV_noinc((SV*)array)));
     }
     
@@ -152,7 +153,10 @@ get_kev(kq, i)
     sv_setiv(AvARRAY(ke2av)[2], ke2[i-1].flags);
     sv_setiv(AvARRAY(ke2av)[3], ke2[i-1].fflags);
     sv_setiv(AvARRAY(ke2av)[4], ke2[i-1].data);
-    av_store(ke2av, 5, SvREFCNT_inc(ke2[i-1].udata));
+    if (ke2[i-1].udata)
+        av_store(ke2av, 5, SvREFCNT_inc(ke2[i-1].udata));
+    else
+        av_store(ke2av, 5, &PL_sv_undef);
     
     RETVAL = newRV_inc((SV*) ke2av);
     

--- ccx_1.1/src/calinput.f.orig	Sun Sep 21 00:10:15 2003
+++ ccx_1.1/src/calinput.f	Sun Sep 21 00:11:34 2003
@@ -544,7 +544,7 @@
          if(i.gt.nlabel) then
             nodeflab(1)='U   '
             nodeflab(3)='S   '
-            jout=1
+            jout=max(jout,1)
             exit
          endif
          if(nodeflab(i).ne.'    ') exit

--- unflasm.c.orig	Thu Nov 22 05:59:32 2001
+++ unflasm.c	Tue Jan 22 10:28:58 2002
@@ -485,15 +485,7 @@
       println("setVariable");
       break;
     case SWFACTION_SETTARGETEXPRESSION:
-      if (targetIndent==1)
-      {
-        --indent;
-        println("end");
-        targetIndent = 0;
-      }
       println("setTargetExpr");
-      ++indent;
-      targetIndent = 1;
       break;
     case SWFACTION_STRINGCONCAT:
       println("concat");
@@ -1008,18 +1000,7 @@
 
     case SWFACTION_SETTARGET:
     {
-      if (targetIndent==1)
-      {
-        --indent;
-        println("end");
-        targetIndent = 0;
-      }
-      if (strlen(p)>0)
-      {
-        println("setTarget '%s'", p);
-        ++indent;
-        targetIndent = 1;
-      }
+      println("setTarget '%s'", p);
       break;
     }
 
@@ -1338,15 +1319,7 @@
   if ((mode >= MODE_UPDATE) && (constend>0))
     rebuildConstantPool();
 
-  if (targetIndent==1)
-  {
-    --indent;
-    println("end");
-    targetIndent = 0;
-  }
-
   --indent;
-
   if (frameNum!=-1) println("end // of frame %i",frameNum);
   free(buffer);
 }

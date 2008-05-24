--- src/sml/translate/support/mk-file-set.sml.orig	2000-01-10 01:09:21.000000000 +0100
+++ src/sml/translate/support/mk-file-set.sml	2007-09-25 18:00:55.000000000 +0200
@@ -9,9 +9,9 @@
       let
 	fun do_one ((name,depends),fs) =
 	  let
-	    val path = Paths.pathConcat (root,Paths.pathFromArcs [name])
+	    val path = Paths.pathConcat (root,Paths.pathFromNative name)
 	    val fname = (Paths.pathToNative path)
-	    val ins = TextIO.openIn (Paths.pathToNative path)
+	    val ins = TextIO.openIn fname
 	    val file = TextIO.inputAll ins
 	    val _ = (TextIO.closeIn ins;print ("Read file:"^fname^"\n"))
 	    val body = PPUtil.s file
@@ -21,4 +21,4 @@
 	  end
       in List.foldl do_one init rest
       end
-  end
\ No newline at end of file
+  end

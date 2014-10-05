--- build-aux/ltmain.sh.orig	2013-10-26 22:53:58 UTC
+++ build-aux/ltmain.sh
@@ -8598,13 +8598,13 @@ func_mode_link ()
 	  #
 	  case $version_type in
 	  # correct linux to gnu/linux during the next big refactor
-	  darwin|linux|osf|windows|none)
+	  darwin|freebsd-elf|linux|osf|windows|none)
 	    func_arith $number_major + $number_minor
 	    current=$func_arith_result
 	    age=$number_minor
 	    revision=$number_revision
 	    ;;
-	  freebsd-aout|freebsd-elf|qnx|sunos)
+	  freebsd-aout|qnx|sunos)
 	    current=$number_major
 	    revision=$number_minor
 	    age=0
@@ -8690,8 +8690,9 @@ func_mode_link ()
 	  ;;
 
 	freebsd-elf)
-	  major=.$current
-	  versuffix=.$current
+	  func_arith $current - $age
+	  major=.$func_arith_result
+	  versuffix=$major.$age.$revision
 	  ;;
 
 	irix | nonstopux)

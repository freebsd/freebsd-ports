$FreeBSD$
--- lib/File/Path.pm.orig	Sat Jan 29 20:23:40 2005
+++ lib/File/Path.pm	Sat Jan 29 20:24:56 2005
@@ -196,7 +196,7 @@ sub rmtree {
 	    # it's also intended to change it to writable in case we have
 	    # to recurse in which case we are better than rm -rf for 
 	    # subtrees with strange permissions
-	    chmod(0777, ($Is_VMS ? VMS::Filespec::fileify($root) : $root))
+	    chmod(0700, ($Is_VMS ? VMS::Filespec::fileify($root) : $root))
 	      or carp "Can't make directory $root read+writeable: $!"
 		unless $safe;
 
@@ -230,7 +230,7 @@ sub rmtree {
 		print "skipped $root\n" if $verbose;
 		next;
 	    }
-	    chmod 0777, $root
+	    chmod 0700, $root
 	      or carp "Can't make directory $root writeable: $!"
 		if $force_writeable;
 	    print "rmdir $root\n" if $verbose;
@@ -252,7 +252,7 @@ sub rmtree {
 		print "skipped $root\n" if $verbose;
 		next;
 	    }
-	    chmod 0666, $root
+	    chmod 0600, $root
 	      or carp "Can't make file $root writeable: $!"
 		if $force_writeable;
 	    print "unlink $root\n" if $verbose;

--- Makefile.PL.orig	2018-04-20 15:05:12 UTC
+++ Makefile.PL
@@ -151,10 +151,3 @@ auto_install();
 auto_provides();
 WriteAll( sign => 0 );
 
-$::VERSION = $required_svn;
-die << "." unless eval {require SVN::Core; SVN::Core->VERSION >= main->VERSION };
-===> Warning: SVN::Core missing or outdated.
-Please manually install SVN::Core by compiling Subversion
-(version $required_svn or above) with SWIG/Perl bindings,
-and try this installation process again.
-.

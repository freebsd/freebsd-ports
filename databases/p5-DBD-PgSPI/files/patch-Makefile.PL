--- Makefile.PL.orig	Fri Jun 22 04:18:50 2001
+++ Makefile.PL	Thu Apr 17 17:51:40 2003
@@ -28,7 +28,7 @@
 my %opts = (
     NAME         => 'DBD::PgSPI',
     VERSION_FROM => 'PgSPI.pm',
-    INC          => "-I$POSTGRES_HOME/include -I$POSTGRES_HOME/backend -I$POSTGRES_HOME/interfaces/libpq -I$dbi_arch_dir",
+    INC          => "-I$POSTGRES_HOME/include -I$POSTGRES_HOME/backend -I$POSTGRES_HOME/interfaces/libpq -I$ENV{LOCALBASE}/include -I$dbi_arch_dir",
     OBJECT       => "PgSPI\$(OBJ_EXT) dbdimp\$(OBJ_EXT)",
     LIBS         => [],
     AUTHOR       => 'Alex Pilosov (alex@pilosov.com)',

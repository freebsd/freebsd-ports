--- ./salome_adm/unix/config_files/check_mpich.m4.orig	2010-06-17 16:08:33.000000000 +0200
+++ ./salome_adm/unix/config_files/check_mpich.m4	2011-01-01 16:53:27.000000000 +0100
@@ -58,15 +58,18 @@
   if test "$WITHMPICH" = "yes";then
     LDFLAGS_old="$LDFLAGS"
     LDFLAGS="$MPI_LIBS $LDFLAGS"
+    LIBS_old="$LIBS"
+    LIBS="$LIBS -lmpl"
     AC_CHECK_LIB(mpich,MPI_Init,WITHMPICH="yes",WITHMPICH="no")
     AC_CHECK_LIB(mpich,MPI_Publish_name,WITHMPI2="yes",WITHMPI2="no")
     LDFLAGS="$LDFLAGS_old"
+    LIBS="$LIBS_old"
   fi
 
   if test "$WITHMPICH" = "yes";then
      WITHMPI="yes"
      mpi_ok=yes
-     MPI_LIBS="$MPI_LIBS -lmpich"
+     MPI_LIBS="$MPI_LIBS -lmpich -lmpl"
   else
      mpi_ok=no
   fi

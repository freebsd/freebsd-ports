commit d7541508936b9ed776e8a39a0bc2a4cc875514d3
Author: Gerald Pfeifer <gerald@pfeifer.com>
Date:   Tue Oct 18 23:41:49 2022 +0200

    ntdll: Fix build on systems without ENODATA.
    
    On FreeBSD 12 and 14 ENODATA is not regularly defined. Cater to that
    in fd_get_file_info() and get_file_info().

diff --git dlls/ntdll/unix/file.c dlls/ntdll/unix/file.c
index c7ba12a5c13..8a599a289f8 100644
--- dlls/ntdll/unix/file.c
+++ dlls/ntdll/unix/file.c
@@ -1565,10 +1565,15 @@ static int fd_get_file_info( int fd, unsigned int options, struct stat *st, ULON
     attr_len = xattr_fget( fd, SAMBA_XATTR_DOS_ATTRIB, attr_data, sizeof(attr_data)-1 );
     if (attr_len != -1)
         *attr |= parse_samba_dos_attrib_data( attr_data, attr_len );
-    else if (errno != ENODATA && errno != ENOTSUP)
+    else
+    {
+        if (errno == ENOTSUP) return ret;
+#ifdef ENODATA
+        if (errno == ENODATA) return ret;
+#endif
         WARN( "Failed to get extended attribute " SAMBA_XATTR_DOS_ATTRIB ". errno %d (%s)\n",
               errno, strerror( errno ) );
-
+    }
     return ret;
 }
 
@@ -1653,10 +1658,15 @@ static int get_file_info( const char *path, struct stat *st, ULONG *attr )
     attr_len = xattr_get( path, SAMBA_XATTR_DOS_ATTRIB, attr_data, sizeof(attr_data)-1 );
     if (attr_len != -1)
         *attr |= parse_samba_dos_attrib_data( attr_data, attr_len );
-    else if (errno != ENODATA && errno != ENOTSUP)
+    else
+    {
+        if (errno == ENOTSUP) return ret;
+#ifdef ENODATA
+        if (errno == ENODATA) return ret;
+#endif
         WARN( "Failed to get extended attribute " SAMBA_XATTR_DOS_ATTRIB " from \"%s\". errno %d (%s)\n",
               path, errno, strerror( errno ) );
-
+    }
     return ret;
 }
 

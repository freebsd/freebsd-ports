--- pblMapTest.c~	2011-07-12 12:35:02.000000000 +0200
+++ pblMapTest.c	2011-07-12 12:34:29.000000000 +0200
@@ -120,44 +120,44 @@
 
     data = (char*)pblMapGetStr( map, "123", &size );
     fprintf( stdout, "pblMapGetStr( map, 123, &size ) size = %lu data = %s\n",
-             size, data );
+             (unsigned long)size, data );
 
     data = (char*)pblMapGetStr( map, "124", &size );
     fprintf( stdout, "pblMapGetStr( map, 124, &size ) size = %lu data = %s\n",
-             size, data );
+             (unsigned long)size, data );
 
     data = (char*)pblMapGetStr( map, "not there", &size );
     fprintf( stdout,
              "pblMapGetStr( map, not there, &size ) size = %lu data = %p\n",
-             size, data );
+             (unsigned long)size, data );
 
     data = (char*)pblMapPutStrStr( map, "123", "123_3", &size );
     fprintf(
              stdout,
              "pblMapPutStrStr( map, 123, 123_3, &size ) size = %lu data = %s\n",
-             size, data );
+             (unsigned long)size, data );
     PBL_FREE(data);
 
     data = (char*)pblMapGetStr( map, "123", &size );
     fprintf( stdout, "pblMapGetStr( map, 123, &size ) size = %lu data = %s\n",
-             size, data );
+             (unsigned long)size, data );
 
     data = (char*)pblMapPutStrStr( map, "125", "125", &size );
     fprintf( stdout,
              "pblMapPutStrStr( map, 125, 125, &size ) size = %lu data = %p\n",
-             size, data );
+             (unsigned long)size, data );
     PBL_FREE(data);
 
     data = (char*)pblMapRemoveStr( map, "125", &size );
     fprintf( stdout,
-             "pblMapRemoveStr( map, 125, &size ) size = %lu data = %s\n", size,
+             "pblMapRemoveStr( map, 125, &size ) size = %lu data = %s\n", (unsigned long)size,
              data );
 	PBL_FREE(data);
 
     data = (char*)pblMapRemoveStr( map, "not there", &size );
     fprintf( stdout,
              "pblMapRemoveStr( map, not there, &size ) size = %lu data = %p\n",
-             size, data );
+             (unsigned long)size, data );
 
     rc = pblMapSize( map );
     fprintf( stdout, "pblMapSize( map ) rc = %d\n", rc );

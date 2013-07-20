--- src/ri/rib.l.orig
+++ src/ri/rib.l
@@ -17,7 +17,7 @@
 
 // Overwrite the YYinput so that it uses libz
 #undef YY_INPUT
-#define YY_INPUT(buf, retval, maxlen)	if ( (retval = gzread(ribin,buf,maxlen)) < 0) 			\
+#define YY_INPUT(buf, retval, maxlen)	if ( (retval = gzread((gzFile)ribin,buf,maxlen)) < 0) 			\
 											YY_FATAL_ERROR( "input in flex scanner failed" );
 
 #endif
@@ -223,7 +223,7 @@
 															TRibFile	*nextFile	=	ribStack->next;
 															rib_delete_buffer( YY_CURRENT_BUFFER );
 #ifdef HAVE_ZLIB
-															gzclose(ribin);
+															gzclose((gzFile)ribin);
 #else
 															fclose(ribin);
 #endif
@@ -243,7 +243,7 @@
 															rib_delete_buffer( YY_CURRENT_BUFFER );
 															
 #ifdef HAVE_ZLIB
-															gzclose(ribin);
+															gzclose((gzFile)ribin);
 #else
 															fclose(ribin);
 #endif

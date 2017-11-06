--- tyui/yui1.cc.orig	2011-09-29 11:50:50 UTC
+++ tyui/yui1.cc
@@ -2665,7 +2665,7 @@ int Edit::saveText( char *Name )
    Screen::sync();
    if ( strlen(name) > 0 && BAK_FILE(eOpt.options) ) {
        FILE *forig = fopen( name, "r" );
-       if ( forig <= 0 ) {
+       if ( forig == NULL ) {
 	   modal *m = new modal( ALIGN_CENTER,
 	   lang( "Can't open original file,\ncreation of backup file skipped",
 		 "Ошибка открытия исходного файла,\nсоздание '.bak'-файла пропущено" ), Warning.get() );
@@ -2675,7 +2675,7 @@ int Edit::saveText( char *Name )
 	   char *nameBack = strdup( Buf1 );
 	   fd = open( nameBack, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR );
 	   FILE *fbak = (fd >= 0 ? fdopen( fd, "w+" ) : 0);
-	   if ( fbak <= 0 ) {
+	   if ( fbak == NULL ) {
 	       sprintf( Buf1, openError.get(), nameBack );
 	       modal *m = new modal( ALIGN_CENTER, (char*)Buf1, Warning.get() );
 	       execUp( m );
@@ -2784,7 +2784,7 @@ write_char:
    unlink( realName );
    fd = open( realName, O_RDWR | O_CREAT | O_TRUNC, fInfo->s.st_mode );
    FILE *forig = (fd >= 0 ? fdopen( fd, "w+" ) : 0);
-   if ( forig <= 0 ) {
+   if ( forig == NULL ) {
       fclose( f );
       sprintf( Buf1, lang("Can't open file\n%s\n\nCheck permissions, your file saved in\n%s",
 			"Ошибка открытия файла\n%s\n\nПроверьте права доступа, файл сохранен в\n%s"), name, tmp );

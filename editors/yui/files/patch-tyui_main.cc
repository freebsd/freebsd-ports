--- tyui/main.cc.orig	2011-09-29 06:55:56 UTC
+++ tyui/main.cc
@@ -1150,7 +1150,7 @@ void Appl::findCtag( char *ctag )
   int line=0;
   Edit *e = NULL;
 
-  while( fgets( buf1024, 1023, f ) > 0 ) {
+  while( fgets( buf1024, 1023, f ) ) {
       buf1024[1023] = 0;
       if ( buf1024[0] == 0x1b || !(s=strtok( buf1024, "\t" )) || strcmp( ctag, s ) )
 	  continue;
@@ -1765,7 +1765,7 @@ void Appl::readOptions()
 	    char *s = NULL;
 	    OPT_info *cinfo = NULL;
 next:
-	    while( fgets( buf1024, 1023, f ) > 0 ) {
+	    while( fgets( buf1024, 1023, f ) ) {
 		buf1024[1023] = 0;
 		s=strtok( buf1024, " \t\r\n" );
 		for( int first=1; s; s=strtok( 0, " \t\r\n" ) ) {
@@ -1862,7 +1862,7 @@ void Appl::readColormap()
 	for( int i=0; i < len_color_info; i++ )
 	    color_info[i].inited = 0;
 next:
-	while( fgets( buf1024, 1023, f ) > 0 ) {
+	while( fgets( buf1024, 1023, f ) ) {
 	    buf1024[1023] = 0;
 	    s=strtok( buf1024, " \t\r\n" );
 	    for( int first=1; s; s=strtok( 0, " \t\r\n" ) ) {
@@ -1945,7 +1945,7 @@ void Appl::readColortrans()
 	char *fg=NULL, *bg=NULL, *s=NULL;
 	int found_term=0, c_fg=0, c_bg=0;
 next:
-	while( fgets( buf1024, 1023, f ) > 0 ) {
+	while( fgets( buf1024, 1023, f ) ) {
 	    if ( fg && bg )
 		break;
 	    buf1024[1023] = 0;
@@ -2027,7 +2027,7 @@ void Appl::readKeymap()
 	    for( int i=0; i < len_com_info; i++ )
 		com_info[i].inited = 0;
 next:
-	    while( fgets( buf1024, 1023, f ) > 0 ) {
+	    while( fgets( buf1024, 1023, f ) ) {
 		COM_info *cinfo = NULL;
 		buf1024[1023] = 0;
 		s=strtok( buf1024, " \t\r\n" );
@@ -2144,7 +2144,7 @@ void Appl::readMacro()
 	}
 	if ( f ) {
 next:
-	    while( fgets( buf1024, 1023, f ) > 0 ) {
+	    while( fgets( buf1024, 1023, f ) ) {
 
 
 	    }
@@ -2480,7 +2480,7 @@ void parse_highlight( const char *home )
   int punctuate = 1;
   tinfo.name = buf2;
   for( int cycle=1; cycle; ) {
-     if ( fgets( buf1024, 1023, f ) <= 0 )
+     if ( fgets( buf1024, 1023, f ) == NULL )
       {
 	cycle=0;
 	if ( ext )
@@ -2615,7 +2615,7 @@ void parse_highlight_html( const char *h
   unsigned param=0, hend=0, ret=0;
   tinfo.name = buf2;
   int ext_flag = 1;
-  while( fgets( buf, 1023, f ) > 0 )
+  while( fgets( buf, 1023, f ) )
    {
      buf[1023] = 0;
      if ( sscanf( buf, "%[^# \t]%u%u", buf2, &param, &hend ) != 3 )

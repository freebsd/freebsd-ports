*** apps/demos/textomatic/TextWrapper.c++.orig	Thu Jan  2 15:29:27 2003
--- apps/demos/textomatic/TextWrapper.c++	Thu Jan  2 15:31:00 2003
***************
*** 77,83 ****
      char    *output       = outbuf;
      //
      if ( global_iconvCodeL2 == (iconv_t)-1   ||
! 	 iconv(global_iconvCodeL2,&input,&inbytesleft,&output,&outbytesleft) == (size_t)-1 )
      {
  	 fprintf( stderr, "textomatic: iconv error.\n" );
  	 (*(UCS2 *)outbuf)=0;
--- 77,83 ----
      char    *output       = outbuf;
      //
      if ( global_iconvCodeL2 == (iconv_t)-1   ||
! 	 iconv(global_iconvCodeL2,(const char **)&input,&inbytesleft,&output,&outbytesleft) == (size_t)-1 )
      {
  	 fprintf( stderr, "textomatic: iconv error.\n" );
  	 (*(UCS2 *)outbuf)=0;
***************
*** 229,235 ****
  	char    *output       = outbuf;
  	//
  	if ( global_iconvCode28 == (iconv_t)-1   ||
! 	     iconv( global_iconvCode28,&input,&inbytesleft,&output,&outbytesleft ) == (size_t)-1 )
  	{
  	     fprintf( stderr, "textomatic: iconv error.\n" );
  	     (*(UCS2 *)outbuf)=0;
--- 229,235 ----
  	char    *output       = outbuf;
  	//
  	if ( global_iconvCode28 == (iconv_t)-1   ||
! 	     iconv( global_iconvCode28,(const char **)&input,&inbytesleft,&output,&outbytesleft ) == (size_t)-1 )
  	{
  	     fprintf( stderr, "textomatic: iconv error.\n" );
  	     (*(UCS2 *)outbuf)=0;

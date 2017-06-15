--- src/ri/rib.l.orig	2008-11-12 07:00:24 UTC
+++ src/ri/rib.l
@@ -17,7 +17,7 @@ static	TRibFile	*ribStack	=	NULL;
 
 // Overwrite the YYinput so that it uses libz
 #undef YY_INPUT
-#define YY_INPUT(buf, retval, maxlen)	if ( (retval = gzread(ribin,buf,maxlen)) < 0) 			\
+#define YY_INPUT(buf, retval, maxlen)	if ( (retval = gzread((gzFile)ribin,buf,maxlen)) < 0) 			\
 											YY_FATAL_ERROR( "input in flex scanner failed" );
 
 #endif
@@ -208,12 +208,12 @@ version												return RIB_VERSION;
 \[													return RIB_ARRAY_BEGIN;
 \]													return RIB_ARRAY_END;
 
-\"[^\"]*\"											{   riblval->string	=	rstrdup(ribtext+1,CRenderer::globalMemory);	riblval->string[strlen(riblval->string)-1] = '\0'; return RIB_TEXT;}
-[+-]?([0-9]+|([0-9]*(\.[0-9]+)?)([eE][+-]?[0-9]+)?)	{	/*sscanf(ribtext,"%f",&riblval->real);*/ riblval->real = (float) atof(ribtext); return RIB_FLOAT; }
-[+-]?([0-9]+|([0-9]+(\.[0-9]*)?)([eE][+-]?[0-9]+)?)	{	/*sscanf(ribtext,"%f",&riblval->real);*/ riblval->real = (float) atof(ribtext); return RIB_FLOAT; }
+\"[^\"]*\"											{   yylval->string	=	rstrdup(ribtext+1,CRenderer::globalMemory);	yylval->string[strlen(yylval->string)-1] = '\0'; return RIB_TEXT;}
+[+-]?([0-9]+|([0-9]*(\.[0-9]+)?)([eE][+-]?[0-9]+)?)	{	/*sscanf(ribtext,"%f",&yylval->real);*/ yylval->real = (float) atof(ribtext); return RIB_FLOAT; }
+[+-]?([0-9]+|([0-9]+(\.[0-9]*)?)([eE][+-]?[0-9]+)?)	{	/*sscanf(ribtext,"%f",&yylval->real);*/ yylval->real = (float) atof(ribtext); return RIB_FLOAT; }
 
 [\t ]												;
-#\!.*												{	riblval->string	=	rstrdup(ribtext+2,CRenderer::globalMemory);	return RIB_STRUCTURE_COMMENT;	}
+#\!.*												{	yylval->string	=	rstrdup(ribtext+2,CRenderer::globalMemory);	return RIB_STRUCTURE_COMMENT;	}
 #.*													;
 \n													{	ribLineno++; }
 <<EOF>>												{
@@ -223,7 +223,7 @@ version												return RIB_VERSION;
 															TRibFile	*nextFile	=	ribStack->next;
 															rib_delete_buffer( YY_CURRENT_BUFFER );
 #ifdef HAVE_ZLIB
-															gzclose(ribin);
+															gzclose((gzFile)ribin);
 #else
 															fclose(ribin);
 #endif
@@ -243,7 +243,7 @@ version												return RIB_VERSION;
 															rib_delete_buffer( YY_CURRENT_BUFFER );
 															
 #ifdef HAVE_ZLIB
-															gzclose(ribin);
+															gzclose((gzFile)ribin);
 #else
 															fclose(ribin);
 #endif

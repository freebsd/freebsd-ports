--- sources/dico.c.orig	Sat Oct 24 16:16:30 1992
+++ sources/dico.c	Mon Apr 15 18:09:04 2002
@@ -19,6 +19,7 @@
     |                                                                       |
     +-----------------------------------------------------------------------+
 */
+#ifndef __FreeBSD__
 #ifndef LINUX
 #ifndef sony
 #ifndef MSDOS
@@ -26,6 +27,7 @@
 #endif
 #endif
 #endif
+#endif
 
 #ifdef sony                             /* Sony News WorkStations        */
 #define UNIX
@@ -40,6 +42,12 @@
 #define MYOS "LINUX" 
 #endif
 
+#ifdef __FreeBSD__                      /* FreeBSD Operating System        */ 
+#define UNIX
+#define ISO_CHARS
+#define MYOS "FreeBSD" 
+#endif
+
 #ifdef MSDOS                            /* Systeme d'operation de disque */
 #define MYOS "MSDOS"                    /* Microsoft :-)                 */
 #endif
@@ -49,7 +57,7 @@
 #define ISO_TERM    3
 #define COMMENT_CHAR 35                 /* '#' ligne de commentaire        */
 
-#define DICT_PATH "/usr/local/lib/dico"  /* path par defaut unix/dos        */
+#define DICT_PATH "%%PREFIX%%/share/dico" /* path par defaut unix/dos      */
 #define DOS_PATH  "lexique"              /* path par defaut Dos uniquement  */
 #define DICT_EXT ".dic"                  /* extension des fichiers dicos    */
 #define VERSION_FILE "version.dic"       /* fichier texte version dico      */
@@ -58,11 +66,13 @@
 #define OK    0
 #define MYVBUF 10240                     /* pour setvbuf() eventuel         */
 
+#ifndef __FreeBSD__
 #ifndef LINUX
 #ifndef sony
 #define MUST_HAVE_BUF                  /* Linux va moins vite avec setvbuf! */
 #endif
 #endif
+#endif
 
 typedef unsigned char byte;
 
@@ -145,7 +155,9 @@
     if(argv[1][0] =='-')                      /* option ligne commande?*/
         return   options( argv[1][1]  );
 
+#ifndef __FreeBSD__
     mybanner();                               /* on dit bonjour...     */
+#endif
 
     while( --argc)                            /* Allez, roulez !       */
     {
@@ -155,7 +167,9 @@
             lookfor( argv[argc] );
     }
 
+#ifndef __FreeBSD__
     fprintf(stderr,"\nTrouve %ld mot%s\n",count, count > 1 ? "s" :"" );
+#endif
 
        return OK ;
 }
@@ -367,7 +381,9 @@
     
     StrLwr( pattern );  /* passe en minuscules comme le dico */
     car = equival (pattern[0]);
+#ifndef __FreeBSD__
     fprintf(stderr, "Recherche %s dans la lettre %c... \n\n", pattern, car) ;
+#endif
 
     sprintf(fname, "%s%s%c%s", dict_path, sep, pattern[0], DICT_EXT ) ;
 
@@ -393,7 +409,11 @@
         if( fmatch(sbuf,pattern) )
         {
             translate( buf ); /* gere terminaux....   */
+#ifndef __FreeBSD__
             printf("\t%s\n", beautify(buf) );
+#else
+            printf("%s\n", beautify(buf) );
+#endif
             count ++ ;
         }
     }
@@ -449,8 +469,11 @@
             if( fmatch(sbuf,pattern) )
             { 
                 translate( buf ) ;
-                buf[0] = ToUpper( buf[0] ) ;  
+#ifndef __FreeBSD__
                 printf("\t%s\n", beautify (buf) );
+#else
+                printf("%s\n", beautify (buf) );
+#endif
                 count ++ ;
             } 
         }
@@ -524,7 +547,9 @@
    byte ville[50], code[6];
    byte *r = ville;
 
+#ifndef __FreeBSD__
    *str = ToUpper ( *str );                 /* Premiere lettre...     */
+#endif
 
     if( ! strchr( str, '\t') )               /* Cas du nom commun      */
     {

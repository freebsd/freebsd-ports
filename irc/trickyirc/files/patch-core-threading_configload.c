--- core/threading/configload.c.orig	2007-12-13 00:35:55.000000000 +0100
+++ core/threading/configload.c	2007-12-13 00:39:37.000000000 +0100
@@ -55,7 +55,7 @@
 	   }
         if ( c == ']' )
            {
-           heading[headingc] = NULL;
+           heading[headingc] = '\0';
            break;
            }
 	}
@@ -74,7 +74,7 @@
 		  c = fgetc(in);
 		  if (( c == 0x0a ) || ( c == EOF ))
 		     {
-		     value[valuec] = NULL;
+		     value[valuec] = '\0';
 		     break;
 		     }
 		  }
@@ -130,27 +130,27 @@
 int quote=0;		/* Weather or not we're in the middle of a quoted block */
 
 /* Reset everything */
-value1[0] = NULL;
-value2[0] = NULL; 
-value3[0] = NULL; 
-value4[0] = NULL; 
-path[0] = NULL; 
+value1[0] = '\0';
+value2[0] = '\0'; 
+value3[0] = '\0'; 
+value4[0] = '\0'; 
+path[0] = '\0'; 
 
 pos = 0;
 while ( 1 )
    {
-   if ( line[pos] == NULL )
+   if ( line[pos] == '\0')
       {
       if ( breaks == 0 )
-         path[pathc] = NULL;
+         path[pathc] = '\0';
       if ( breaks == 1 )
-         value1[valuec] = NULL;
+         value1[valuec] = '\0';
       if ( breaks == 2 )
-         value2[valuec] = NULL;
+         value2[valuec] = '\0';
       if ( breaks == 3 )
-         value3[valuec] = NULL;
+         value3[valuec] = '\0';
       if ( breaks == 4 ) 
-         value4[valuec] = NULL;
+         value4[valuec] = '\0';
       break;
       }
    if (( line[pos] == '#' ) && ( quote == 0 ))
@@ -184,15 +184,15 @@
       {
       /* hit dead space, inc the break count, and zing to the next text */
       if ( breaks == 0 )
-         path[pathc] = NULL;
+         path[pathc] = '\0';
       if ( breaks == 1 )
-         value1[valuec] = NULL;
+         value1[valuec] = '\0';
       if ( breaks == 2 )
-         value2[valuec] = NULL;
+         value2[valuec] = '\0';
       if ( breaks == 3 )
-         value3[valuec] = NULL;
+         value3[valuec] = '\0';
       if ( breaks == 4 )
-         value4[valuec] = NULL;
+         value4[valuec] = '\0';
       while ( 1 )
          {
          pos++;

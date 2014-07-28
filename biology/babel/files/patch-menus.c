
$FreeBSD$

--- menus.c.orig	Tue Jan 21 16:52:36 1997
+++ menus.c	Sun Nov 18 16:43:32 2001
@@ -63,9 +63,9 @@
     }
   }
   printf("Input file name : ");
-  gets(InfileName);
+  fgets(InfileName, BUFF_SIZE, stdin);
   printf("Keywords : ");
-  gets(InputKeywords);
+  fgets(InputKeywords, BUFF_SIZE, stdin);
 
   if (strlen(InputKeywords) < 1)
     strcpy(InputKeywords,"KEYWORDS GO HERE");
@@ -108,11 +108,11 @@
     }
   }
   printf("Output file name : ");
-  gets(OutfileName);
+  fgets(OutfileName, BUFF_SIZE, stdin);
   if (has_keywords)
   {
     printf("Keywords : ");
-    gets(OutputKeywords);
+    fgets(OutputKeywords, BUFF_SIZE, stdin);
     if (strlen(OutputKeywords) < 1)
       strcpy(OutputKeywords,"KEYWORDS GO HERE");
   }
@@ -167,7 +167,7 @@
   while (done == FALSE)
   {
     printf("Choice : ");
-    gets(choice_string);
+    fgets(choice_string, sizeof(choice_string), stdin);
     for (i = 0; i < (int) strlen(choice_string); i++)
     {
       if (!isdigit(choice_string[i]))

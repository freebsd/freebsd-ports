--- vrml.y.orig	Sun Dec  1 22:46:12 2002
+++ vrml.y	Sun Dec  1 22:46:55 2002
@@ -84,7 +84,6 @@
 #define	YYMAXDEPTH	(1024 * 8 * 1000)
 
 int yyerror(char *s);
-int yyparse(void);
 int yylex(void);
 
 %} 
@@ -546,6 +545,7 @@
 			AddNode(audioClip);
 			PushNode(VRML_NODETYPE_AUDIOCLIP, audioClip);
 		}
+		;
 
 AudioClip
 	: AudioClipBegin NodeBegin AudioClipElements NodeEnd
@@ -1928,6 +1928,7 @@
 		{
 			((MaterialNode *)GetCurrentNodeObject())->setTransparency($2);
 		}
+		;
 
 MaterialBegin	
 	: MATERIAL 
@@ -2410,6 +2411,7 @@
 			pset->initialize();
 			PopNode();
 		}
+		;
 
 /******************************************************************
 *

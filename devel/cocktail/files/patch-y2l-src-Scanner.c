--- ../../work/cocktail-9309//./y2l/src/Scanner.c	Tue Feb 15 14:29:16 1994
+++ ./y2l/src/Scanner.c	Wed Mar 31 23:32:57 2004
@@ -1,4 +1,4 @@
-/* $Id: Scanner.c,v 2.20 1993/08/31 14:47:10 grosch rel $ */
+/* $Id: Scanner.c,v 2.19 1993/08/18 17:28:53 grosch rel $ */
 
 # define bool		char
 # define true		1
@@ -78,8 +78,7 @@
 	tScanAttribute	Attribute	;
 	void		(* Scanner_Exit) () = yyExit;
  
-static	yyCombType	yyComb		[yyTableSize   + 1] = {
-{0, 0},
+static	yyCombType	yyComb		[yyTableSize   + 1] = {{1, 0},
 {0, 0},
 {0, 0},
 {0, 0},
@@ -2503,7 +2502,7 @@
 {0, 0},
 {0, 0},
 };
-static	yyCombType *	yyBasePtr	[yyDStateCount + 1] = { 0,
+static	yyCombType *	yyBasePtr	[yyDStateCount + 1] = {& yyComb [0],
 & yyComb [0],
 & yyComb [0],
 & yyComb [125],
@@ -2658,7 +2657,7 @@
 & yyComb [201],
 & yyComb [0],
 };
-static	yyStateRange	yyDefault	[yyDStateCount + 1] = { 0,
+static	yyStateRange	yyDefault	[yyDStateCount + 1] = {0,
 28,
 1,
 19,
@@ -2813,7 +2812,7 @@
 59,
 0,
 };
-static	yyStateRange	yyEobTrans	[yyDStateCount + 1] = { 0,
+static	yyStateRange	yyEobTrans	[yyDStateCount + 1] = {0,
 0,
 0,
 49,
@@ -2969,27 +2968,21 @@
 0,
 };
 
-static	yyStateRange	yyInitStateStack [yyInitBufferSize] = {yyDefaultState};
+static	yyStateRange	yyInitStateStack [yyInitBufferSize] = {0};
 static	yyStateRange *	yyStateStack	= yyInitStateStack;
 static	unsigned long	yyStateStackSize= yyInitBufferSize;
-static	yyStateRange	yyStartState	= STD;
-static	yyStateRange	yyPreviousStart	= STD;
+static	yyStateRange	yyStartState	= 0;
+static	yyStateRange	yyPreviousStart	= 1;
 
-static	unsigned char	yyInitChBuffer [yyInitBufferSize] = {
-   '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
-   '\0', '\0', '\0', '\0', '\0', '\0', '\0', yyEolCh,
-   yyEobCh, '\0',
-};
-static  short		yySourceFile	= StdIn;
-static	bool		yyIsFirstCall	= true;
-static	bool		yyEof		= false;
-static	unsigned char *	yyChBufferPtr	= yyInitChBuffer;
-static	unsigned char *	yyChBufferStart	= & yyInitChBuffer [16];
-static	unsigned long	yyChBufferSize	= yyInitBufferSize;
-static	unsigned char *	yyChBufferIndex	= & yyInitChBuffer [16];
-static	int		yyBytesRead	= 0;
-static	int		yyLineCount	= 1;
-static	unsigned char *	yyLineStart	= & yyInitChBuffer [16 - 1];
+static  short		yySourceFile	;
+static	bool		yyEof		;
+static	unsigned char *	yyChBufferPtr	;
+static	unsigned char *	yyChBufferStart	;
+static	unsigned long	yyChBufferSize	;
+static	unsigned char *	yyChBufferIndex	= ((unsigned char *) yyComb) + 2; /* dirty trick */
+static	int		yyBytesRead	;
+static	int		yyLineCount	;
+static	unsigned char *	yyLineStart	;
 
 static	struct {
 	short		yySourceFile	;
@@ -3001,7 +2994,7 @@
 	int		yyBytesRead	;
 	int		yyLineCount	;
 	unsigned char *	yyLineStart	;
-	} yyFileStack [yyFileStackSize + 1], * yyFileStackPtr = & yyFileStack [1];
+	} yyFileStack [yyFileStackSize + 1], * yyFileStackPtr = yyFileStack;
 
 static	unsigned char	yyToLower	[] = {
 '\0', '\1', '\2', '\3', '\4', '\5', '\6', '\7',
@@ -3061,6 +3054,7 @@
 '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
 };
  
+static	void	yyInitialize	();
 static	void	yyErrorMessage	ARGS((int yyErrorCode));
 static	char	input		();
 /* line 29 "yacc.rex" */
@@ -3691,7 +3685,9 @@
 	 }
 	 goto yyBegin;
  
-      case yyDNoState:
+      case yyDNoState:				/* automatic initialization */
+	 yyInitialize ();
+	 yySourceFile = StdIn;
 	 goto yyBegin;
 
 case 60:
@@ -3766,6 +3762,18 @@
    }
 }
  
+void BeginFile
+# if defined __STDC__ | defined __cplusplus
+   (char * yyFileName)
+# else
+   (yyFileName) char * yyFileName;
+# endif
+   {
+      yyInitialize ();
+      yySourceFile = BeginSource (yyFileName);
+      if (yySourceFile < 0) yyErrorMessage (4);
+   }
+
 static void yyInitialize ()
    {
       if (yyFileStackPtr >= yyFileStack + yyFileStackSize) yyErrorMessage (2);
@@ -3792,23 +3800,8 @@
       yyBytesRead	   = 0;
       yyLineCount	   = 1;
       yyLineStart	   = & yyChBufferStart [-1];
-   }
-
-void BeginFile
-# if defined __STDC__ | defined __cplusplus
-   (char * yyFileName)
-# else
-   (yyFileName) char * yyFileName;
-# endif
-   {
-      if (yyIsFirstCall) {
-	 ReleaseArray ((char * *) & yyChBufferPtr, & yyChBufferSize, sizeof (char));
-	 yyFileStackPtr --;		
-	 yyIsFirstCall = false;
-      }
-      yyInitialize ();
-      yySourceFile = BeginSource (yyFileName);
-      if (yySourceFile < 0) yyErrorMessage (4);
+      if (yyStartState == 0) yyStartState = STD;
+      yyStateStack [0]	   = yyDefaultState;	/* stack underflow sentinel */
    }
 
 void CloseFile ()

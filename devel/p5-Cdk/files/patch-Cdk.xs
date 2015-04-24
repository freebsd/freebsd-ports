--- Cdk.xs.orig	2012-03-24 11:42:10 UTC
+++ Cdk.xs
@@ -2436,10 +2436,9 @@ PostProcess(object,functionRef)
 void
 Draw(object)
 	CDKMENU *	object
-	int		Box = sv2int ($arg);
 	CODE:
 	{
-	   drawCDKMenu (object, Box);
+	   drawCDKMenu (object, TRUE);
 	}
 
 void
@@ -6587,18 +6586,20 @@ SetContents(object,list)
 void
 SetFillerChar(object,fille)
 	CDKALPHALIST*	object
-	chtype	filler = sv2chtype ($arg);
+	SV * fille
 	CODE:
 	{
+	   chtype	filler = sv2chtype (fille);
 	   setCDKAlphalistFillerChar (object,filler);
 	}
 
 void
 SetHighlight(object,highlight)
 	CDKALPHALIST*	object
-	chtype	filler = sv2chtype ($arg);
+	SV * highlight
 	CODE:
 	{
+	   chtype	filler = sv2chtype (highlight);
 	   setCDKAlphalistHighlight (object,filler);
 	}
 

--- src/skpcmd.c.orig	1991-07-12 04:21:24 UTC
+++ src/skpcmd.c
@@ -84,13 +84,17 @@ static DEFAULT SkpCtU()		/* skip control
 	BOOLEAN	TTrace;		/* temp: holds trace flag */
 
 	if (CBfPtr == CStEnd)
+		{
 		if (MStTop < 0)			/* if not in a macro */
 			{
 			ErrUTC();		/* unterminated command */
 			return FAILURE;
 			}
 		else
+			{
 			return SUCCESS;
+			}
+		}
 	++CBfPtr;
 	TTrace = TraceM;			/* save trace mode flag */
 	TraceM = FALSE;				/* keep FindES from tracing */
@@ -145,13 +149,17 @@ static DEFAULT SkpDqu()		/* skip a " (do
 {
 	DBGFEN(3,"SkpDqu",NULL);
 	if (CBfPtr == CStEnd)			/* if end of command string */
+		{
 		if (MStTop < 0)			/* if not in a macro */
 			{
 			ErrUTC();		/* unterminated command */
 			return FAILURE;
 			}
 		else
+			{
 			return SUCCESS;
+			}
+		}
 	++CBfPtr;
 	switch (To_Upper(*CBfPtr)) {
 		case 'A':
@@ -232,13 +240,17 @@ static DEFAULT SkpSkp()		/* */
 static DEFAULT SkpF()			/* skip one of the F commands */
 {
 	if (CBfPtr == CStEnd)
+		{
 		if (MStTop < 0)			/* if not in a macro */
 			{
 			ErrUTC();		/* unterminated command */
 			return FAILURE;
 			}
 		else
+			{
 			return SUCCESS;
+			}
+		}
 	++CBfPtr;
 
 	switch (To_Upper(*CBfPtr)) {
@@ -320,13 +332,17 @@ static DEFAULT SkpCrt()		/* skip a ^ (ca
 	WORD	CDummy;
 
 	if (CBfPtr == CStEnd)			/* if end of command string */
+		{
 		if (MStTop < 0)			/* if macro stack empty */
 			{
 			ErrUTC();		/* unterminated command */
 			return FAILURE;
 			}
 		else
+			{
 			return SUCCESS;
+			}
+		}
 	++CBfPtr;
 	if ((*CBfPtr >= 'A') && (*CBfPtr <= '_'))
 		CDummy = *CBfPtr - 'A';
@@ -360,13 +376,17 @@ static DEFAULT SkpE()			/* skip one of t
 /* Y */ SkpSkp,    /* Z */ SkpSkp
 	};
 	if (CBfPtr == CStEnd)
+		{
 		if (MStTop < 0)			/* if not in a macro */
 			{
 			ErrUTC();		/* unterminated command */
 			return FAILURE;
 			}
 		else
+			{
 			return SUCCESS;
+			}
+		}
 
 	++CBfPtr;
 	TmpChr = To_Upper(*CBfPtr);

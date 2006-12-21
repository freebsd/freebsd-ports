--- ./shellcmd.c.orig	Thu Dec  1 16:16:19 2005
+++ ./shellcmd.c	Wed Dec 20 14:34:05 2006
@@ -199,7 +199,7 @@
 	return(false);
 }
 
-static bool GetUINT32String(Tcl_Interp *localInterpreter,const char *theString,UINT32 *theNumber)
+static bool GetUINT32String(Tcl_Interp *localInterpreter,char *theString,UINT32 *theNumber)
 // convert theString to a UINT32
 // return false if the conversion failed, and fill the Tcl result
 {
@@ -668,7 +668,7 @@
 	{
 		for(theIndex=1;!fail&&(int)theIndex<objc;theIndex++)
 		{
-			if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[theIndex],NULL),&pathArgc,&pathArgv)==TCL_OK)
+			if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[theIndex],NULL),&pathArgc,(char ***)&pathArgv)==TCL_OK)
 			{
 				theMenu=NULL;										// start at the root
 				if(GetEditorMenu(pathArgc,pathArgv,&theMenu))
@@ -720,7 +720,7 @@
 		{
 			if(GetBoolean(localInterpreter,objv[3],&active))
 			{
-				if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[1],NULL),&pathArgc,&pathArgv)==TCL_OK)
+				if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[1],NULL),&pathArgc,(char ***)&pathArgv)==TCL_OK)
 				{
 					if(CreateEditorMenu(pathArgc,pathArgv,theRelationship,Tcl_GetStringFromObj(objv[4],NULL),Tcl_GetStringFromObj(objv[5],NULL),Tcl_GetStringFromObj(objv[6],NULL),active))
 					{
@@ -1223,7 +1223,7 @@
 	fail=false;
 	if(objc==3)
 	{
-		if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[2],NULL),&listArgc,&listArgv)==TCL_OK)
+		if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[2],NULL),&listArgc,(char ***)&listArgv)==TCL_OK)
 		{
 			if((selectedElements=(bool *)MNewPtrClr(sizeof(bool)*listArgc)))	// get array of "falses"
 			{
@@ -3696,19 +3696,19 @@
 		{
 			if(ShellBufferNotBusy(localInterpreter,theBuffer))
 			{
-				if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[2],NULL),&listArgc,&listArgv)==TCL_OK)
+				if(Tcl_SplitList(localInterpreter,Tcl_GetStringFromObj(objv[2],NULL),&listArgc,(char ***)&listArgv)==TCL_OK)
 				{
 					EditorStartSelectionChange(theBuffer);
 					fail=false;
 					for(i=0;!fail&&i<listArgc;i++)
 					{
-						if(Tcl_SplitList(localInterpreter,listArgv[i],&elementArgc,&elementArgv)==TCL_OK)
+						if(Tcl_SplitList(localInterpreter,listArgv[i],&elementArgc,(char ***)&elementArgv)==TCL_OK)
 						{
 							if(elementArgc==2)
 							{
-								if(GetUINT32String(localInterpreter,elementArgv[0],&startPosition))
+								if(GetUINT32String(localInterpreter,(char *)elementArgv[0],&startPosition))
 								{
-									if(GetUINT32String(localInterpreter,elementArgv[1],&endPosition))
+									if(GetUINT32String(localInterpreter,(char *)elementArgv[1],&endPosition))
 									{
 										startPosition=ForcePositionIntoRange(theBuffer,startPosition);
 										endPosition=ForcePositionIntoRange(theBuffer,endPosition);
@@ -4604,7 +4604,7 @@
 		fail;
 
 	fail=false;
-	if(Tcl_SplitList(localInterpreter,endExpressionList,&argc,&argv)==TCL_OK)	// get list of end expressions
+	if(Tcl_SplitList(localInterpreter,endExpressionList,&argc,(char ***)&argv)==TCL_OK)	// get list of end expressions
 	{
 		for(i=0;!fail&&i<argc;i++)
 		{
@@ -4654,11 +4654,11 @@
 			SetMappingStartExpressionPiece(theMapping,expressionPiece);
 			if(ParseEndExpressions(localInterpreter,theMap,theMapping,argv[2]))
 			{
-				if(GetUINT32String(localInterpreter,argv[3],&startStyle))
+				if(GetUINT32String(localInterpreter,(char *)argv[3],&startStyle))
 				{
-					if(GetUINT32String(localInterpreter,argv[4],&betweenStyle))
+					if(GetUINT32String(localInterpreter,(char *)argv[4],&betweenStyle))
 					{
-						if(GetUINT32String(localInterpreter,argv[5],&endStyle))
+						if(GetUINT32String(localInterpreter,(char *)argv[5],&endStyle))
 						{
 							SetMappingStyles(theMapping,startStyle,betweenStyle,endStyle);
 							return(true);
@@ -4704,13 +4704,13 @@
 		i,j;
 
 	fail=false;
-	if(Tcl_SplitList(localInterpreter,mapContents,&listArgc,&listArgv)==TCL_OK)	// make list of command/parameter
+	if(Tcl_SplitList(localInterpreter,mapContents,&listArgc,(char ***)&listArgv)==TCL_OK)	// make list of command/parameter
 	{
 		for(i=0;(i<listArgc)&&!fail;i+=2)					// step over each command, parameter list pair
 		{
 			if(MatchToken(listArgv[i],syntaxMapCommands,&syntaxMapToken))
 			{
-				if(Tcl_SplitList(localInterpreter,listArgv[i+1],&argc,&argv)==TCL_OK)	// make parameters into arguments
+				if(Tcl_SplitList(localInterpreter,listArgv[i+1],&argc,(char ***)&argv)==TCL_OK)	// make parameters into arguments
 				{
 					switch(syntaxMapToken)
 					{
@@ -4749,7 +4749,7 @@
 							{
 								if((theMapping=LocateSyntaxStyleMapping(theMap,argv[0])))
 								{
-									if(Tcl_SplitList(localInterpreter,argv[1],&mappinglistArgc,&mappinglistArgv)==TCL_OK)	// make parameters into arguments
+									if(Tcl_SplitList(localInterpreter,argv[1],&mappinglistArgc,(char ***)&mappinglistArgv)==TCL_OK)	// make parameters into arguments
 									{
 										for(j=0;j<mappinglistArgc&&!fail;j++)
 										{

--- py.c.orig	Thu Jan  8 10:45:51 2004
+++ py.c	Fri Jan  9 21:36:21 2004
@@ -465,11 +465,11 @@
 		iPYInsertPoint--;
 
 		if (!strlen (strFindString)) {
+		    char            strTemp[MAX_USER_INPUT + 1];
+
 		    if (!iPYSelected)
 			return IRV_CLEAN;
 
-		    char            strTemp[MAX_USER_INPUT + 1];
-
 		    val = strlen (strFindString);
 		    strcpy (strTemp, pySelected[iPYSelected - 1].strPY);
 		    strcat (strTemp, strFindString);
@@ -816,6 +816,9 @@
     char            str[2];
     int             iVal;
 
+    char           *pBase = NULL, *pPhrase;
+    int             iType;
+
     if (findMap.iMode == PARSE_ERROR || (bSingleHZMode && findMap.iHZCount > 1)) {
 	uMessageDown = 0;
 	iCandPageCount = 0;
@@ -886,9 +889,6 @@
     else
 	PYGetCandWordsBackward ();
 
-    char           *pBase = NULL, *pPhrase;
-    int             iType;
-
     str[1] = '\0';
     uMessageDown = 0;
 
@@ -981,11 +981,6 @@
  */
 void PYCreateAuto (void)
 {
-    strPYAuto[0] = '\0';
-
-    if (findMap.iHZCount == 1)
-	return;
-
     PYCandIndex     candPos;
     int             val;
     int             iMatchedLength;
@@ -997,6 +992,11 @@
     char            strMap[MAX_WORDS_USER_INPUT * 2 + 1];
     int             iCount;
 
+    strPYAuto[0] = '\0';
+
+    if (findMap.iHZCount == 1)
+	return;
+
     strPYAutoMap[0] = '\0';
     str[2] = '\0';
 
@@ -1126,15 +1126,19 @@
 
 char           *PYGetCandWord (int iIndex)
 {
-    if (!iCandWordCount)
-	return NULL;
-
     char           *pBase = NULL, *pPhrase = NULL;
     char           *pBaseMap = NULL, *pPhraseMap = NULL;
     uint           *pIndex = NULL;
     Bool            bAddNewPhrase = True;
     int             i;
 
+    char            strHZString[MAX_WORDS_USER_INPUT * 2 + 1];
+
+    int             iLen;
+
+    if (!iCandWordCount)
+	return NULL;
+
     if (iIndex > (iCandWordCount - 1))
 	iIndex = iCandWordCount - 1;
 
@@ -1190,14 +1194,10 @@
     if (pPhrase)
 	strcat (messageDown[uMessageDown].strMsg, pPhrase);
 
-    char            strHZString[MAX_WORDS_USER_INPUT * 2 + 1];
-
     strcpy (strHZString, pBase);
     if (pPhrase)
 	strcat (strHZString, pPhrase);
 
-    int             iLen;
-
     iLen = strlen (strHZString) / 2;
     if (iLen == findMap.iHZCount || PYCandWords[iIndex].iWhich == PY_CAND_SYMBOL) {
 	strPYAuto[0] = '\0';
@@ -1374,15 +1374,15 @@
 
 void PYGetPhraseCandWords (SEARCH_MODE mode)
 {
-    if (findMap.iHZCount == 1)
-	return;
-
     PYCandIndex     candPos;
     char            str[3];
     int             val, iMatchedLength;
     char            strMap[MAX_WORDS_USER_INPUT * 2 + 1];
     PyPhrase       *phrase;
 
+    if (findMap.iHZCount == 1)
+	return;
+
     str[0] = findMap.strMap[0][0];
     str[1] = findMap.strMap[0][1];
     str[2] = '\0';
@@ -1446,6 +1446,8 @@
 {
     char            str[MAX_WORDS_USER_INPUT * 2 + 1];
 
+    int             i = 0, j, iStart = 0;
+
     strcpy (str, PYFAList[pos.iPYFA].pyBase[pos.iBase].strHZ);
     strcat (str, phrase->strPhrase);
     if (strPYAuto[0]) {
@@ -1455,8 +1457,6 @@
 	}
     }
 
-    int             i = 0, j, iStart = 0;
-
     switch (phraseOrder) {
     case AD_NO:
 	if (mode == SM_PREV) {
@@ -2111,14 +2111,14 @@
  */
 Bool PYAddUserPhrase (char *phrase, char *map)
 {
-    //如果短于两个汉字，则不能组成词组
-    if (strlen (phrase) < 4)
-	return False;
-
     PyPhrase       *userPhrase, *newPhrase, *temp;
     char            str[3];
     int             i, j, k, iTemp;
 
+    //如果短于两个汉字，则不能组成词组
+    if (strlen (phrase) < 4)
+	return False;
+
     str[0] = map[0];
     str[1] = map[1];
     str[2] = '\0';
@@ -2510,11 +2510,15 @@
  */
 INPUT_RETURN_VALUE PYGetLegendCandWords (SEARCH_MODE mode)
 {
+    int             i, j;
+
+    PyPhrase       *phrase;
+
+    char            strTemp[2];
+
     if (!strPYLegendSource[0])
 	return IRV_TO_PROCESS;
 
-    int             i, j;
-
     if (mode == SM_FIRST) {
 	iLegendCandPageCount = 0;
 	iLegendCandWordCount = 0;
@@ -2575,8 +2579,6 @@
 	}
     }
 
-    PyPhrase       *phrase;
-
     phrase = pyBaseForLengend->userPhrase->next;
     for (i = 0; i < pyBaseForLengend->iUserPhrase; i++) {
 	if (strlen (strPYLegendSource) == 2) {
@@ -2632,8 +2634,6 @@
       _NEWPAGE:
 	;
     }
-
-    char            strTemp[2];
 
     uMessageUp = 2;
     strcpy (messageUp[0].strMsg, "联想：");

--- wbx.c.orig	Thu Jan  8 07:47:50 2004
+++ wbx.c	Fri Jan  9 21:39:35 2004
@@ -147,11 +147,11 @@
 
     fpDict = fopen (strPath, "rt");
     if (fpDict) {
+	int             i = 0;
+
 	iWBFH = CalculateRecordNumber (fpDict);
 	wbfh = (WBFH *) malloc (sizeof (WBFH) * iWBFH);
 
-	int             i = 0;
-
 	for (i = 0; i < iWBFH; i++) {
 	    if (EOF == fscanf (fpDict, "%s\n", wbfh[i].strWBFH))
 		break;
@@ -469,11 +469,11 @@
 
 char           *WBGetCandWord (int iIndex)
 {
+    char           *pCandWord;
+
     if (!strcmp (strCodeInput, "zzzz"))
 	return WBGetFHCandWord (iIndex);
 
-    char           *pCandWord;
-
     bIsInLegend = False;
 
     if (iCandWordCount) {
@@ -502,6 +502,10 @@
 
 INPUT_RETURN_VALUE WBGetPinyinCandWords (SEARCH_MODE mode)
 {
+    //下面将拼音的候选字表转换为五笔的样式
+    int             i;
+    WBRECORD       *pWB;
+
     if (mode == SM_FIRST) {
 	bSingleHZMode = True;
 	strcpy (strFindString, strCodeInput + 1);
@@ -517,10 +521,6 @@
     else
 	PYGetCandWords (mode);
 
-    //下面将拼音的候选字表转换为五笔的样式
-    int             i;
-    WBRECORD       *pWB;
-
     for (i = 0; i < iCandWordCount; i++) {
 	pWB = FindWuBiCode (PYFAList[PYCandWords[i].cand.base.iPYFA].pyBase[PYCandWords[i].cand.base.iBase].strHZ, False);
 	if (pWB)
@@ -718,11 +718,11 @@
 
 int WBFindFirstMatchCode (void)
 {
+    int             i = 0;
+
     if (!wubiDictHead)
 	return -1;
 
-    int             i = 0;
-
     wubiDictCurrent = wubiDictHead->next;
     while (wubiDictCurrent != wubiDictHead) {
 	if (!CompareWBCode (strCodeInput, wubiDictCurrent->strCode)) {
@@ -742,11 +742,11 @@
  */
 WBRECORD       *FindWuBiCode (char *strHZ, Bool bMode)
 {
+    WBRECORD       *recTemp;
+
     if (!wubiDictHead)
 	return NULL;
 
-    WBRECORD       *recTemp;
-
     recTemp = wubiDictHead->next;
     while (recTemp != wubiDictHead) {
 	if (!strcmp (recTemp->strHZ, strHZ)) {
@@ -1063,11 +1063,13 @@
 
 INPUT_RETURN_VALUE WBGetFHCandWords (SEARCH_MODE mode)
 {
+    char            strTemp[2];
+
+    int             i;
+
     if (!iWBFH)
 	return IRV_DO_NOTHING;
 
-    char            strTemp[2];
-
     strTemp[1] = '\0';
     uMessageDown = 0;
 
@@ -1093,8 +1095,6 @@
 	}
     }
 
-    int             i;
-
     for (i = 0; i < iMaxCandWord; i++) {
 	strTemp[0] = i + 1 + '0';
 	if (i == 9)
@@ -1139,6 +1139,10 @@
 
 Bool WBPhraseTips (char *strPhrase)
 {
+    //首先要判断是不是已经在词库中
+    WBRECORD       *recTemp = NULL;
+    INT8            i;
+
     if (!wubiDictHead)
 	return False;
 
@@ -1149,10 +1153,6 @@
     //如果strPhrase只有一个汉字，这个工作也不需要了
     if (strlen (strPhrase) < 4)
 	return False;
-
-    //首先要判断是不是已经在词库中
-    WBRECORD       *recTemp = NULL;
-    INT8            i;
 
     for (i = 0; i < (strlen (strPhrase) - 2); i += 2) {
 	recTemp = wubiDictHead->next;

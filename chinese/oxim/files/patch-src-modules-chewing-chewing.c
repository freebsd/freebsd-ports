--- src/modules/chewing/chewing.c.orig	Mon Jun 12 00:02:39 2006
+++ src/modules/chewing/chewing.c	Thu Sep  7 17:45:14 2006
@@ -14,7 +14,9 @@
 #include "oximtool.h"
 #include "module.h"
 
+#if 0
 #include <iconv.h>
+#endif
 
 /* the following keystate masks are defined by oxim */
 #define CAPS_MASK (2)
@@ -28,17 +30,19 @@
 static int CapsLockMode  = 0; /* 0:小寫, 1:大寫 */
 static char *selKey_define = "1234567890";
 
+#if 0
 void preconvert(char *input, char *output, int n_char);
 wchar_t convert(wchar_t input);
+#endif
 
 static int bAddPhraseForward = 0;
 static uch_t etymon_list[N_KEYCODE];
 
-int MakeInpinfo(inpinfo_t *inpinfo, ChewingOutput *pgo);
+int MakeInpinfo(inpinfo_t *inpinfo);
 
-int CallSetConfig(inpinfo_t *inpinfo, ChewingData *pgdata)
+int CallSetConfig(inpinfo_t *inpinfo, ChewingContext *ctx)
 {
-    ConfigData config;
+    ChewingConfigData config;
     int i;
 
     config.selectAreaLen = 100;
@@ -48,14 +52,14 @@
     for (i = 0; i < 10;i++)
         config.selKey[i] = selKey_define[i];
 
-    SetConfig(pgdata, &config);
+    chewing_Configure(ctx, &config);
     return 0;
 }
 
 static int
-ChewingInit(void *conf, char *objname)
+ChewingInit(void *context, char *objname)
 {
-    ChewingConf *cf = (ChewingConf *)conf ;
+    ChewingContext *ctx = (ChewingContext *)context ;
 
     /* TODO : 這裡要改為偵測新酷音詞庫存放路徑 */
     char *prefix = CHEWING_DATA_DIR;
@@ -95,14 +99,12 @@
 
     if (oxim_setting_GetInteger(im_settings, "KeyMap", &KeyMap))
     {
-	if (KeyMap < KB_DEFAULT && KeyMap > KB_HANYU_PINYING)
+	if (KeyMap < KB_DEFAULT && KeyMap > KB_HANYU_PINYIN)
 	{
 	    KeyMap = KB_DEFAULT;
 	}
     }
 
-    cf->kb_type = KeyMap;
-
     char *pho_key = "1qaz2wsxedcrfv5tgbyhnujm8ik,9ol.0p;/-7634";
     char *pho_name[41] = {"ㄅ","ㄆ","ㄇ","ㄈ","ㄉ","ㄊ","ㄋ","ㄌ","ㄍ","ㄎ","ㄏ","ㄐ","ㄑ","ㄒ","ㄓ","ㄔ","ㄕ","ㄖ","ㄗ","ㄘ","ㄙ","ㄧ","ㄨ","ㄩ","ㄚ","ㄛ","ㄜ","ㄝ","ㄞ","ㄟ","ㄠ","ㄡ","ㄢ","ㄣ","ㄤ","ㄥ","ㄦ","˙","ˊ","ˇ","ˋ"};
     int keylen = strlen(pho_key), i, idx;
@@ -114,10 +116,7 @@
     }
 
     /* Initialize Chewing */
-    ReadTree(prefix);
-    InitChar(prefix);
-    InitDict(prefix);
-    ReadHash(prefix);
+    chewing_Init(prefix, prefix);
 
     oxim_settings_destroy(im_settings);
     return True;
@@ -127,14 +126,15 @@
 ChewingXimInit(void *conf, inpinfo_t *inpinfo)
 {
     static char cchBuffer[MAX_PHONE_SEQ_LEN];
-    ChewingConf *cf = (ChewingConf *) conf;
+    ChewingContext *ctx = (ChewingContext *) conf;
     int i;
 
-    inpinfo->iccf = (ChewingData *) calloc(1, sizeof(ChewingData));
-    inpinfo->etymon_list = (cf->kb_type == KB_HANYU_PINYING) ? NULL : etymon_list;
+    inpinfo->iccf = chewing_new();
+
+    CallSetConfig(inpinfo, (ChewingContext *) inpinfo->iccf);
 
-    InitChewing(inpinfo->iccf, cf);
-    CallSetConfig(inpinfo, (ChewingData *) inpinfo->iccf);
+    chewing_set_KBType( inpinfo->iccf, KeyMap );
+    inpinfo->etymon_list = (KeyMap == KB_HANYU_PINYIN) ? NULL : etymon_list;
 
     inpinfo->lcch = (uch_t *) calloc(MAX_PHONE_SEQ_LEN, sizeof(uch_t));
     inpinfo->lcch_grouping = (ubyte_t *) calloc(MAX_PHONE_SEQ_LEN, sizeof(ubyte_t));
@@ -163,33 +163,29 @@
     return True;
 }
 
-void CommitString(inpinfo_t *inpinfo, ChewingOutput *pgo)
+void CommitString(inpinfo_t *inpinfo)
 {
     int i ;
     char *str;
-    char *output;
+    ChewingOutput *pgo = ((ChewingContext *) inpinfo->iccf)->output;
     bzero(inpinfo->cch, sizeof(char)*MAX_PHONE_SEQ_LEN);
     str = (char *) calloc(MAX_PHONE_SEQ_LEN,sizeof(char));
-    output = (char *) calloc(MAX_PHONE_SEQ_LEN / 2 * chewing_codeset, sizeof(char));
     for (i = 0; i < pgo->nCommitStr; i++)
         strcat(str, (const char *) pgo->commitStr[i].s);
-    preconvert(str, output, strlen(str));
-    strcpy(inpinfo->cch, output);
+    strcpy(inpinfo->cch, str);
     free(str);
-    free(output);
 }
 
 static unsigned int 
 ChewingXimEnd(void *conf, inpinfo_t *inpinfo)
 {
-    ChewingOutput gOut ;
     int rtn ;
 
     /* if preedit exists, commit the string */
-    OnKeyEnter(inpinfo->iccf, &gOut);
+    chewing_handle_Enter(inpinfo->iccf);
 
-    rtn = MakeInpinfo(inpinfo, &gOut);
-    free(inpinfo->iccf);
+    rtn = MakeInpinfo(inpinfo);
+    chewing_free((ChewingContext*) inpinfo->iccf);
     free(inpinfo->s_keystroke);
     free(inpinfo->lcch);
     free(inpinfo->mcch);
@@ -202,7 +198,7 @@
     return rtn ;
 }      
 
-void ShowChoose(inpinfo_t *inpinfo, ChoiceInfo *pci, ChewingOutput *pgo)
+void ShowChoose(inpinfo_t *inpinfo, ChoiceInfo *pci)
 {
     int i,no,k,len, kk;
     char *output;
@@ -218,16 +214,12 @@
         // in the last page, no will exceed nTotalChoice
         if( no >= pci->nTotalChoice ) 
             break;
-        output = (char *) calloc(
-                        strlen(pci->totalChoiceStr[no]) * chewing_codeset + 1, 
-                        sizeof(char));
-        preconvert(pci->totalChoiceStr[no], output, strlen(pci->totalChoiceStr[no]));
+	output = pci->totalChoiceStr[no];
         // for each char in the phrase, copy to mcch
         for (k = 0, kk = 0; output[k] != '\0'; k += chewing_codeset, kk++)
 	{
 	    memcpy(inpinfo->mcch[len++].s, &(output[k]), chewing_codeset) ;
 	}
-        free(output);
         // set grouping to the length of the phrase
         inpinfo->mcch_grouping[i+1] = kk;
 
@@ -251,22 +243,23 @@
     inpinfo->n_mcch = len ;
 }
 
-void ShowText(inpinfo_t *inpinfo, ChewingOutput *pgo)
+void ShowText(inpinfo_t *inpinfo)
 {
     int i;
+    ChewingOutput *pgo = ((ChewingContext *) inpinfo->iccf)->output;
     bzero(inpinfo->lcch, sizeof(uch_t)*MAX_PHONE_SEQ_LEN) ;
     for (i = 0; i < pgo->chiSymbolBufLen; i++)
     {
-	pgo->chiSymbolBuf[i].wch = convert(pgo->chiSymbolBuf[i].wch);
 	strcpy((char *)inpinfo->lcch[i].s, (char *)pgo->chiSymbolBuf[i].s);
     }
     inpinfo->n_lcch = pgo->chiSymbolBufLen ;
 }
 
-void ShowInterval(inpinfo_t *inpinfo, ChewingOutput *pgo)
+void ShowInterval(inpinfo_t *inpinfo)
 {
     int i, k, begin, len, count, nGroup ;
     int label[MAX_PHONE_SEQ_LEN] ;
+    ChewingOutput *pgo = ((ChewingContext *) inpinfo->iccf)->output;
 
     if( pgo->chiSymbolBufLen == 0) {
         inpinfo->lcch_grouping[0] = 0 ;
@@ -305,34 +298,35 @@
         inpinfo->lcch_grouping[0] = nGroup ;
 }
 
-void ShowStateAndZuin(inpinfo_t *inpinfo, ChewingOutput *pgo)
+void ShowStateAndZuin(inpinfo_t *inpinfo)
 {
     int i, a , len = 0;
+    ChewingOutput *pgo = ((ChewingContext *) inpinfo->iccf)->output;
 
     bzero( inpinfo->s_keystroke, sizeof(uch_t)*(3 + MAX_PHRASE_LEN));
-    ChewingData *iccf = inpinfo->iccf;	
+    ChewingContext *iccf = inpinfo->iccf;	
 
     if(pgo->bShowMsg)
     {
         for(i = 0; i < pgo->showMsgLen; i++)
 	{
-	    inpinfo->s_keystroke[i].uch = (uchar_t)convert(pgo->showMsg[i].wch);
+	    inpinfo->s_keystroke[i].uch = (uchar_t)(pgo->showMsg[i].wch);
 	}
 	inpinfo->keystroke_len = pgo->showMsgLen ;
     }
     else
     {
 	// 漢語拼音 
-	if (iccf->zuinData.kbtype == KB_HANYU_PINYING)
+	if (iccf->data->zuinData.kbtype == KB_HANYU_PINYIN)
 	{
-	   for (i=0 ; i < PINYING_SIZE; i++)
+	   for (i=0 ; i < PINYIN_SIZE; i++)
 	   {
-		if (iccf->zuinData.pinYingData.keySeq[i] != '\0')
+		if (iccf->data->zuinData.pinYinData.keySeq[i] != '\0')
 		{
-		    inpinfo->s_keystroke[i].uch = iccf->zuinData.pinYingData.keySeq[i];
+		    inpinfo->s_keystroke[i].uch = iccf->data->zuinData.pinYinData.keySeq[i];
 		}
 	   } 
-	   inpinfo->keystroke_len = strlen(iccf->zuinData.pinYingData.keySeq);
+	   inpinfo->keystroke_len = strlen(iccf->data->zuinData.pinYinData.keySeq);
 	}
 	else
 	{
@@ -340,7 +334,7 @@
 	    {
 		if(pgo->zuinBuf[i].s[0] != '\0')
 		{
-		    inpinfo->s_keystroke[a++].uch = (uchar_t)convert(pgo->zuinBuf[i].wch);
+		    inpinfo->s_keystroke[a++].uch = (uchar_t)(pgo->zuinBuf[i].wch);
 		    ++ len;
 		}
 	    }
@@ -349,13 +343,15 @@
     }
 }
 
-void SetCursor(inpinfo_t *inpinfo, ChewingOutput *pgo)
+void SetCursor(inpinfo_t *inpinfo)
 {
+    ChewingOutput *pgo = ((ChewingContext *) inpinfo->iccf)->output;
     inpinfo->edit_pos = pgo->chiSymbolCursor;
 }
 
-int MakeInpinfo(inpinfo_t *inpinfo, ChewingOutput *pgo)
+int MakeInpinfo(inpinfo_t *inpinfo)
 {
+    ChewingOutput *pgo = ((ChewingContext *) inpinfo->iccf)->output;
     int rtnValue = 0 ;
 
     if(pgo->keystrokeRtn & KEYSTROKE_ABSORB)
@@ -364,20 +360,20 @@
         rtnValue |= IMKEY_IGNORE;
     if(pgo->keystrokeRtn & KEYSTROKE_COMMIT) {
         rtnValue |= IMKEY_COMMIT;
-        CommitString(inpinfo, pgo);
+        CommitString(inpinfo);
     }
 
     if(pgo->pci->nPage != 0) { // in selection mode
-        ShowChoose(inpinfo,pgo->pci,pgo);
+        ShowChoose(inpinfo,pgo->pci);
         inpinfo->guimode &= ~GUIMOD_LISTCHAR; 
     }
     else { // not in selection mode
-        ShowText(inpinfo, pgo);
-        ShowInterval(inpinfo, pgo);
+        ShowText(inpinfo);
+        ShowInterval(inpinfo);
         inpinfo->guimode |= GUIMOD_LISTCHAR;
     }
-    ShowStateAndZuin(inpinfo, pgo);
-    SetCursor(inpinfo, pgo);
+    ShowStateAndZuin(inpinfo);
+    SetCursor(inpinfo);
     return rtnValue;
 }
 
@@ -385,7 +381,6 @@
 ChewingKeystroke(void *conf, inpinfo_t *inpinfo, keyinfo_t *keyinfo)
 {
     KeySym keysym = keyinfo->keysym;
-    ChewingOutput gOut ;
     int rtn ;
     static KeySym last_key = 0;
 
@@ -406,61 +401,58 @@
 
     // set Chinese / English mode by keystate
     if( keyinfo->keystate & CAPS_MASK ) { // uppercase
-            SetChiEngMode( inpinfo->iccf, SYMBOL_MODE);
+            chewing_set_ChiEngMode( inpinfo->iccf, SYMBOL_MODE);
     }
     else {  // lower case 
-            SetChiEngMode( inpinfo->iccf, CHINESE_MODE);
+            chewing_set_ChiEngMode( inpinfo->iccf, CHINESE_MODE);
     }
 
     // check no ctrl key was pressed
     if(keyinfo->keystate >= 0 && !(keyinfo->keystate & CTRL_MASK ) && !(keyinfo->keystate & ShiftMask) ) {
         switch(keysym) {
             case XK_Escape:
-                OnKeyEsc(inpinfo->iccf, &gOut) ;
+                chewing_handle_Esc(inpinfo->iccf) ;
                 inpinfo->n_mcch = 0;
                 break ;
             case XK_Return:
-                OnKeyEnter(inpinfo->iccf, &gOut) ;
+                chewing_handle_Enter(inpinfo->iccf) ;
                 inpinfo->n_mcch = 0;
                 break ;
             case XK_Delete:
-                OnKeyDel(inpinfo->iccf, &gOut) ;
+                chewing_handle_Del(inpinfo->iccf) ;
 		break ;
             case XK_BackSpace:
-                OnKeyBackspace(inpinfo->iccf, &gOut) ;
+                chewing_handle_Backspace(inpinfo->iccf) ;
                 break ;
             case XK_Up:
-                OnKeyUp(inpinfo->iccf, &gOut);
+                chewing_handle_Up(inpinfo->iccf);
                 break ;
             case XK_Down:
-                OnKeyDown(inpinfo->iccf, &gOut) ;
+                chewing_handle_Down(inpinfo->iccf) ;
                 break ;
             case XK_Left:
-                OnKeyLeft(inpinfo->iccf, &gOut) ;
+                chewing_handle_Left(inpinfo->iccf) ;
                 break ;
             case XK_Right:
-                OnKeyRight(inpinfo->iccf, &gOut) ;
+                chewing_handle_Right(inpinfo->iccf) ;
                 break ;
             case XK_Home:
-                OnKeyHome(inpinfo->iccf, &gOut);
+                chewing_handle_Home(inpinfo->iccf);
 		break;
 	    case XK_End:
-                OnKeyEnd(inpinfo->iccf, &gOut);
+                chewing_handle_End(inpinfo->iccf);
                 break;
             case XK_Tab:
-                if (last_key == XK_Tab) // double click TAB
-                    OnKeyDblTab(inpinfo->iccf, &gOut);
-                else
-                    OnKeyTab(inpinfo->iccf, &gOut);
+                chewing_handle_Tab(inpinfo->iccf);
                 break;
             case XK_Caps_Lock:
-                OnKeyCapslock(inpinfo->iccf, &gOut);
+                chewing_handle_Capslock(inpinfo->iccf);
                 break;
             case ' ': /* Space */
-                OnKeySpace(inpinfo->iccf, &gOut);
+                chewing_handle_Space(inpinfo->iccf);
                 break;
             default:
-                OnKeyDefault(inpinfo->iccf, keysym, &gOut);
+                chewing_handle_Default(inpinfo->iccf, (char) keysym );
                 inpinfo->n_mcch = 0;
                 break;
         }
@@ -468,26 +460,26 @@
     else if (keyinfo->keystate & ShiftMask) {
 	switch ( keysym ) {
 	    case XK_Left:
-		OnKeyShiftLeft(inpinfo->iccf, &gOut) ;
+		chewing_handle_ShiftLeft(inpinfo->iccf) ;
                 break ;
             case XK_Right:
-                OnKeyShiftRight(inpinfo->iccf, &gOut) ;
+                chewing_handle_ShiftRight(inpinfo->iccf) ;
                 break;
             default:
-                OnKeyDefault(inpinfo->iccf, keysym, &gOut);
+                chewing_handle_Default(inpinfo->iccf, (char) keysym);
                 inpinfo->n_mcch = 0;
             }
     }
     else if (keyinfo->keystate & CTRL_MASK) {  // Ctrl-key Mask
 	// We need to fill the 'gOut' variable for output.
 	    if (keysym <= '9' && keysym >= '0') 
-		OnKeyCtrlNum(inpinfo->iccf,keysym,&gOut);
+		chewing_handle_CtrlNum(inpinfo->iccf, (char) keysym);
             else 
-                OnKeyCtrlOption(inpinfo->iccf, keysym - 'a' + 1, &gOut);
+                chewing_handle_CtrlOption(inpinfo->iccf, keysym - 'a' + 1);
     }
 
     last_key = keysym;
-    rtn = MakeInpinfo(inpinfo, &gOut);
+    rtn = MakeInpinfo(inpinfo);
     return rtn ;
 }
 
@@ -498,6 +490,7 @@
     return False;
 }                              
 
+#if 0
 /* UTF-8 support */
 void
 preconvert(char *input, char *output, int n_char)
@@ -533,6 +526,7 @@
     iconv_close(cd);
     return output.wch;
 }
+#endif
 
 static int ChewingTerminate(void *conf)
 {
@@ -554,7 +548,7 @@
         zh_chewing_comments 
     },					/* comments */
     zh_chewing_valid_objname,		/* valid_objname */
-    sizeof(ChewingConf),		/* conf_size */
+    sizeof(ChewingConfigData),		/* conf_size */
     ChewingInit,			/* init */
     ChewingXimInit,			/* xim_init */
     ChewingXimEnd,			/* xim_end */

Break overly clever and inconsistent logic of detecting a tool to
display a dialog box, always stick to zenity. Don't try to beep
too.

--- gameheaders/stratagus-tinyfiledialogs.h.orig	2021-07-17 05:26:07 UTC
+++ gameheaders/stratagus-tinyfiledialogs.h
@@ -3676,6 +3676,7 @@ static int gdialogPresent(void)
 
 static int osascriptPresent(void)
 {
+	return 0;
     static int lOsascriptPresent = -1 ;
     if (lOsascriptPresent < 0) {
         gWarningDisplayed |= !!getenv("SSH_TTY");
@@ -3779,6 +3780,7 @@ int tfd_zenity3Present(void)
 
 int tfd_kdialogPresent(void)
 {
+	return 0;
 	static int lKdialogPresent = -1 ;
 	char lBuff[MAX_PATH_OR_CMD] ;
     FILE *lIn ;
@@ -3974,6 +3976,7 @@ static void sigHandler(int signum)
 
 void tinyfd_beep(void)
 {
+	return;
     char lDialogString[256] ;
     FILE *lIn ;
 

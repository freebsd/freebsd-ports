--- vendor/github.com/msteinert/pam/v2/transaction.go.orig	2024-05-22 21:03:02 UTC
+++ vendor/github.com/msteinert/pam/v2/transaction.go
@@ -257,14 +257,6 @@ const (
 	Ruser Item = C.PAM_RUSER
 	// UserPrompt is the string use to prompt for a username.
 	UserPrompt Item = C.PAM_USER_PROMPT
-	// FailDelay is the app supplied function to override failure delays.
-	FailDelay Item = C.PAM_FAIL_DELAY
-	// Xdisplay is the X display name
-	Xdisplay Item = C.PAM_XDISPLAY
-	// Xauthdata is the X server authentication data.
-	Xauthdata Item = C.PAM_XAUTHDATA
-	// AuthtokType is the type for pam_get_authtok
-	AuthtokType Item = C.PAM_AUTHTOK_TYPE
 )
 
 // SetItem sets a PAM information item.

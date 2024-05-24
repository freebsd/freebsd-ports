--- vendor/github.com/msteinert/pam/v2/errors.go.orig	2024-05-22 21:03:02 UTC
+++ vendor/github.com/msteinert/pam/v2/errors.go
@@ -79,13 +79,6 @@ const (
 	ErrModuleUnknown Error = C.PAM_MODULE_UNKNOWN
 	// ErrBadItem indicates a bad item passed to pam_*_item().
 	ErrBadItem Error = C.PAM_BAD_ITEM
-	// ErrConvAgain indicates a conversation function is event driven and data
-	// is not available yet.
-	ErrConvAgain Error = C.PAM_CONV_AGAIN
-	// ErrIncomplete indicates to please call this function again to complete
-	// authentication stack. Before calling again, verify that conversation
-	// is completed.
-	ErrIncomplete Error = C.PAM_INCOMPLETE
 )
 
 // Error returns the error message for the given status.

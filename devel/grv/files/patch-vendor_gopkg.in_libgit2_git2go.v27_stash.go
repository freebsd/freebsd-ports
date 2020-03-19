--- vendor/gopkg.in/libgit2/git2go.v27/stash.go.orig	2019-01-04 13:40:18 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/stash.go
@@ -171,7 +171,7 @@ func (opts *StashApplyOptions) toC() (
 
 		optsC = &C.git_stash_apply_options{
 			version: C.GIT_STASH_APPLY_OPTIONS_VERSION,
-			flags:   C.git_stash_apply_flags(opts.Flags),
+			flags:   C.uint32_t(opts.Flags),
 		}
 		populateCheckoutOpts(&optsC.checkout_options, &opts.CheckoutOptions)
 		if opts.ProgressCallback != nil {

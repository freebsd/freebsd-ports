--- vendor/gopkg.in/libgit2/git2go.v27/merge.go.orig	2019-01-04 13:40:18 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/merge.go
@@ -132,7 +132,7 @@ func (mo *MergeOptions) toC() *C.git_merge_options {
 	}
 	return &C.git_merge_options{
 		version:          C.uint(mo.Version),
-		flags:            C.git_merge_flag_t(mo.TreeFlags),
+		flags:            C.uint32_t(mo.TreeFlags),
 		rename_threshold: C.uint(mo.RenameThreshold),
 		target_limit:     C.uint(mo.TargetLimit),
 		file_favor:       C.git_merge_file_favor_t(mo.FileFavor),
@@ -374,7 +374,7 @@ func populateCMergeFileOptions(c *C.git_merge_file_opt
 	c.our_label = C.CString(options.OurLabel)
 	c.their_label = C.CString(options.TheirLabel)
 	c.favor = C.git_merge_file_favor_t(options.Favor)
-	c.flags = C.git_merge_file_flag_t(options.Flags)
+	c.flags = C.uint32_t(options.Flags)
 	c.marker_size = C.ushort(options.MarkerSize)
 }
 

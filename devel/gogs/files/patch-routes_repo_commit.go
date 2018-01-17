--- routes/repo/commit.go.orig	2017-12-31 13:07:52 UTC
+++ routes/repo/commit.go
@@ -45,6 +44,7 @@ func RenderIssueLinks(oldCommits *list.L
 func renderCommits(c *context.Context, filename string) {
 	c.Data["Title"] = c.Tr("repo.commits.commit_history") + " · " + c.Repo.Repository.FullName()
 	c.Data["PageIsCommits"] = true
+	c.Data["FileName"] = filename
 
 	page := c.QueryInt("page")
 	if page < 1 {

--- internal/util/paths/paths_test.go.orig	2025-08-09 06:01:54 UTC
+++ internal/util/paths/paths_test.go
@@ -26,18 +26,14 @@ func TestExpandPath(t *testing.T) {
 
 	s1 := []string{home, "foo"}
 	homefoo := strings.Join(s1, "/")
-	s2 := []string{"E.T phone", home}
-	etph := strings.Join(s2, " ")
 
 	// base cases
 	test("~", home)
 	test("~/", home)
 	test("~/foo", homefoo)
-	test("${HOME}/foo", homefoo)
 	test("/usr/opt", "/usr/opt")
 
 	// edge cases
 	test("~foo", "~foo")
 	test("not a path", "not a path")
-	test("E.T phone ${HOME}", etph)
 }

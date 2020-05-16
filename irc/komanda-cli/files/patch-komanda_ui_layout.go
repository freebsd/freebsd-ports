--- komanda/ui/layout.go.orig	2020-05-15 19:20:57 UTC
+++ komanda/ui/layout.go
@@ -63,7 +63,7 @@ func Layout(g *gocui.Gui) error {
 				fmt.Fprintln(view, version.ColorLogo())
 				fmt.Fprintln(view, color.String(
 					config.C.Color.Green,
-					fmt.Sprintf("  Version: %s%s  Source Code: %s\n",
+					fmt.Sprintf("  Version: %s.%s  Source Code: %s\n",
 						version.Version, version.Build, version.Website),
 				),
 				)

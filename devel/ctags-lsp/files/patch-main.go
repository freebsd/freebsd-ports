--- main.go.orig	2026-04-30 20:08:48 UTC
+++ main.go
@@ -83,7 +83,7 @@ func parseFlags(args []string, output io.Writer) (*Con
 	}
 	flagset.BoolVar(&config.showVersion, "version", false, "")
 	flagset.BoolVar(&config.benchmark, "benchmark", false, "")
-	flagset.StringVar(&config.ctagsBin, "ctags-bin", "ctags", "")
+	flagset.StringVar(&config.ctagsBin, "ctags-bin", "uctags", "")
 	flagset.StringVar(&config.tagfilePath, "tagfile", "", "")
 	flagset.StringVar(&config.languages, "languages", "", "")
 

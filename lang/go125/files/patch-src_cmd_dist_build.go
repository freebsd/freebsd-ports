--- src/cmd/dist/build.go.orig	2024-03-29 15:27:02 UTC
+++ src/cmd/dist/build.go
@@ -891,6 +891,20 @@ func runInstall(pkg string, ch chan struct{}) {
 			asmArgs = append(asmArgs, "-D", "GOPPC64_power8")
 		}
 	}
+	if goarch == "arm" {
+		// Define GOARM_value from goarm, which can be either a version
+		// like "6", or a version and a FP mode, like "7,hardfloat".
+		switch {
+		case strings.Contains(goarm, "7"):
+			asmArgs = append(asmArgs, "-D", "GOARM_7")
+			fallthrough
+		case strings.Contains(goarm, "6"):
+			asmArgs = append(asmArgs, "-D", "GOARM_6")
+			fallthrough
+		default:
+			asmArgs = append(asmArgs, "-D", "GOARM_5")
+		}
+	}
 	goasmh := pathf("%s/go_asm.h", workdir)
 
 	// Collect symabis from assembly code.

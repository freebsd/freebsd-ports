--- internal/backends/compression/png/setup.go.orig	2025-10-12 17:20:54 UTC
+++ internal/backends/compression/png/setup.go
@@ -76,6 +76,7 @@ func CheckPngquantInstalled() (string, error) {
		"linux":   config.PngquantBinaryName,
		"windows": config.PngquantBinaryName + ".exe",
		"darwin":  config.PngquantBinaryName,
+		"freebsd": config.PngquantBinaryName,
	}

	destFolder := filepath.Join(config.GowallConfig.OutputFolder, "compression", "pngquant")

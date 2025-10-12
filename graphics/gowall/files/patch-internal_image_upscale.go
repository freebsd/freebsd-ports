--- internal/image/upscale.go.orig	1979-11-30 00:00:00 UTC
+++ internal/image/upscale.go
@@ -7,7 +7,7 @@ import (
	"os/exec"
	"path/filepath"

-	"github.com/Achno/gowall/config"
+	// "github.com/Achno/gowall/config"
	imageio "github.com/Achno/gowall/internal/image_io"
	types "github.com/Achno/gowall/internal/types"
	"github.com/Achno/gowall/internal/upscaler"
@@ -35,6 +35,7 @@ func (p *UpscaleProcessor) Process(img image.Image, th
		"windows": "realesrgan-ncnn-vulkan.exe",
		"darwin":  "realesrgan-ncnn-vulkan",
		"linux":   "realesrgan-ncnn-vulkan",
+		"freebsd": "realesrgan-ncnn-vulkan",
	}

	binary, err := utils.FindBinary(binaryNames, destFolder)

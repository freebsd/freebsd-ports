--- src/custom.cpp.orig	2026-09-17 07:30:24 UTC
+++ src/custom.cpp
@@ -7689,10 +7689,10 @@ static int REGPARAM2 custom_wput_1(uaecptr addr, uae_u
 		} else {
 			int reg = addr & 0x1fe;
 			if (aga_mode) {
-				custom_wput_dma64(reg, static_cast<uaecptr>(NULL), v, c);
-			} else {
-				write_drga(reg, static_cast<uaecptr>(NULL), v);
-			}
+				custom_wput_dma64(reg, 0, v, c);
+            } else {
+				write_drga(reg, 0, v);
+            }
 		}
 	}
 	return ret;

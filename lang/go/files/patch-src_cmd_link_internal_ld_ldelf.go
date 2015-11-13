--- src/cmd/link/internal/ld/ldelf.go.orig	2015-09-09 01:24:01 UTC
+++ src/cmd/link/internal/ld/ldelf.go
@@ -629,6 +629,13 @@ func ldelf(f *obj.Biobuf, pkg string, le
 			if strings.HasPrefix(sym.name, ".Linfo_string") { // clang does this
 				continue
 			}
+
+			if sym.name == "" && sym.type_ == 0 && sect.name == ".debug_str" {
+				// This reportedly happens with clang 3.7 on ARM.
+				// See issue 13139.
+				continue
+			}
+
 			Diag("%s: sym#%d: ignoring %s in section %d (type %d)", pn, i, sym.name, sym.shndx, sym.type_)
 			continue
 		}

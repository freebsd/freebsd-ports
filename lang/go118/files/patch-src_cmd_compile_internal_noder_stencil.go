Revert "[release-branch.go1.18] cmd/compile: fix missing dict pass for type assertions"
https://go-review.googlesource.com/c/go/+/417615

--- src/cmd/compile/internal/noder/stencil.go.orig	2022-07-12 15:22:53 UTC
+++ src/cmd/compile/internal/noder/stencil.go
@@ -1297,10 +1297,10 @@ func (g *genInst) dictPass(info *instInfo) {
 				m = convertUsingDictionary(info, info.dictParam, m.Pos(), mce.X, m, m.Type(), false)
 			}
 		case ir.ODOTTYPE, ir.ODOTTYPE2:
-			dt := m.(*ir.TypeAssertExpr)
-			if !dt.Type().HasShape() && !dt.X.Type().HasShape() {
+			if !m.Type().HasShape() {
 				break
 			}
+			dt := m.(*ir.TypeAssertExpr)
 			var rt ir.Node
 			if dt.Type().IsInterface() || dt.X.Type().IsEmptyInterface() {
 				ix := findDictType(info, m.Type())

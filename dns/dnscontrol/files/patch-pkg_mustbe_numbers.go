Fix compile issue on FreeBSD 14.4/i386

pkg/mustbe/numbers.go:122:19: math.MaxUint32 (untyped int constant 4294967295) overflows int

--- pkg/mustbe/numbers.go.orig	1979-11-30 00:00:00 UTC
+++ pkg/mustbe/numbers.go
@@ -114,12 +114,12 @@ func Uint32(arg any) uint32 {
 	case uint32:
 		return v
 	case uint:
-		if v > math.MaxUint32 {
+		if uint64(v) > uint64(math.MaxUint32) {
 			panic(fmt.Sprintf("value %v overflows uint32", arg))
 		}
 		return uint32(v)
 	case int:
-		if v < 0 || v > math.MaxUint32 {
+		if v < 0 || int64(v) > int64(math.MaxUint32) {
 			panic(fmt.Sprintf("value %v overflows uint32", arg))
 		}
 		return uint32(v)

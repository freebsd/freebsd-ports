Compile error at least on FreeBSD 12.1/i386
providers/octodns/octoyaml/read.go:266:17: constant 4294967295 overflows int

Obtained from:	https://github.com/StackExchange/dnscontrol/issues/736

--- providers/octodns/octoyaml/read.go.orig	2020-05-03 15:43:54 UTC
+++ providers/octodns/octoyaml/read.go
@@ -12,7 +12,6 @@ import (
 	"fmt"
 	"io"
 	"io/ioutil"
-	"math"
 	"reflect"
 	"strconv"
 
@@ -263,8 +262,8 @@ func decodeTTL(ttl interface{}) (uint32, error) {
 		return uint32(t), fmt.Errorf("decodeTTL failed to parse (%s): %w", s, err)
 	case int:
 		i := ttl.(int)
-		if i < 0 || i > math.MaxUint32 {
-			return 0, fmt.Errorf("ttl won't fit in 32-bits (%d)", i)
+		if i < 0 {
+			return 0, fmt.Errorf("ttl cannot be negative (%d)", i)
 		}
 		return uint32(i), nil
 	}

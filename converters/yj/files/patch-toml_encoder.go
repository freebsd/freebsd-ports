--- toml/encoder.go.orig	2020-07-25 19:25:50 UTC
+++ toml/encoder.go
@@ -15,7 +15,7 @@ type Encoder struct {
 	NaN, PosInf, NegInf interface{}
 }
 
-func (e *Encoder) Encode(normal interface{}) (yaml interface{}, err error) {
+func (e *Encoder) Encode(normal interface{}) (toml interface{}, err error) {
 	defer catchFailure(&err)
 	et := encodeTracker{Encoder: e}
 	return et.denormalize(normal), nil

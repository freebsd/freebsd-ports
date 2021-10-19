--- plv8_type.cc.orig	2021-10-19 07:08:47 UTC
+++ plv8_type.cc
@@ -600,7 +600,7 @@ CreateExternalArray(void *data, plv8_external_array_ty
 	array->SetInternalField(0, External::New(isolate, DatumGetPointer(datum)));
 
 	// needs to be a copy, as the data could go away
-	memcpy(buffer->GetContents().Data(), data, byte_size);
+	memcpy(buffer->GetBackingStore()->Data(), data, byte_size);
 
 	return array;
 }
@@ -710,7 +710,7 @@ ToScalarDatum(Handle<v8::Value> value, bool *isnull, p
 		{
 			if (value->IsUint8Array() || value->IsInt8Array()) {
 				v8::Handle<v8::Uint8Array> array = v8::Handle<v8::Uint8Array>::Cast(value);
-				void *data = array->Buffer()->GetContents().Data();
+				void *data = array->Buffer()->GetBackingStore()->Data();
 				int		len = array->Length();
 				size_t		size = len + VARHDRSZ;
 				void	   *result = (void *) palloc(size);
@@ -722,7 +722,7 @@ ToScalarDatum(Handle<v8::Value> value, bool *isnull, p
 
 			if (value->IsUint16Array() || value->IsInt16Array()) {
 				v8::Handle<v8::Uint16Array> array = v8::Handle<v8::Uint16Array>::Cast(value);
-				void *data = array->Buffer()->GetContents().Data();
+				void *data = array->Buffer()->GetBackingStore()->Data();
 				int		len = array->Length();
 				size_t		size = (len * 2) + VARHDRSZ;
 				void	   *result = (void *) palloc(size);
@@ -734,7 +734,7 @@ ToScalarDatum(Handle<v8::Value> value, bool *isnull, p
 
 			if (value->IsUint32Array() || value->IsInt32Array()) {
 				v8::Handle<v8::Uint32Array> array = v8::Handle<v8::Uint32Array>::Cast(value);
-				void *data = array->Buffer()->GetContents().Data();
+				void *data = array->Buffer()->GetBackingStore()->Data();
 				int		len = array->Length();
 				size_t		size = (len * 4) + VARHDRSZ;
 				void	   *result = (void *) palloc(size);
@@ -746,7 +746,7 @@ ToScalarDatum(Handle<v8::Value> value, bool *isnull, p
 
 			if (value->IsArrayBuffer()) {
 				v8::Handle<v8::ArrayBuffer> array = v8::Handle<v8::ArrayBuffer>::Cast(value);
-				void *data = array->GetContents().Data();
+				void *data = array->GetBackingStore()->Data();
 				int		len = array->ByteLength();
 				size_t		size = len + VARHDRSZ;
 				void	   *result = (void *) palloc(size);

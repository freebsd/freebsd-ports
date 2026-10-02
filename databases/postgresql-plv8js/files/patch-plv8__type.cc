--- plv8_type.cc.orig	2026-06-01 05:04:31 UTC
+++ plv8_type.cc
@@ -575,7 +575,7 @@ CreateExternalArray(void *data, plv8_external_array_ty
 	default:
 		throw js_error("unexpected array type");
 	}
-	array->SetInternalField(0, External::New(isolate, DatumGetPointer(datum)));
+	array->SetInternalField(0, External::New(isolate, DatumGetPointer(datum), v8::kExternalPointerTypeTagDefault));
 
 	// needs to be a copy, as the data could go away
 	memcpy(buffer->GetBackingStore()->Data(), data, byte_size);
@@ -593,7 +593,7 @@ ExtractExternalArrayDatum(Handle<v8::Value> value)
 	if (value->IsTypedArray())
 	{
 		Handle<Object> object = Handle<Object>::Cast(value);
-		return Handle<External>::Cast(object->GetInternalField(0))->Value();
+		return Handle<External>::Cast(object->GetInternalField(0).As<v8::Value>())->Value(v8::kExternalPointerTypeTagDefault);
 	}
 
 	return NULL;

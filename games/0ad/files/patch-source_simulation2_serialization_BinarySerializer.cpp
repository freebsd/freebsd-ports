--- source/simulation2/serialization/BinarySerializer.cpp.orig	2022-08-21 12:45:40 UTC
+++ source/simulation2/serialization/BinarySerializer.cpp
@@ -52,7 +52,7 @@ static u8 GetArrayType(js::Scalar::Type arrayType)
 	case js::Scalar::Uint8Clamped:
 		return SCRIPT_TYPED_ARRAY_UINT8_CLAMPED;
 	default:
-		LOGERROR("Cannot serialize unrecognized typed array view: %d", arrayType);
+		LOGERROR("Cannot serialize unrecognized typed array view: %d", static_cast<int>(arrayType));
 		throw PSERROR_Serialize_InvalidScriptValue();
 	}
 }

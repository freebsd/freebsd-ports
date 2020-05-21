--- json_object.c.orig	2020-04-19 03:36:00 UTC
+++ json_object.c
@@ -735,7 +735,7 @@ int64_t json_object_get_int64(const struct json_object
 		// so cast to tell the compiler it's ok to round up.
 		if (jso->o.c_double >= (double)INT64_MAX)
 			return INT64_MAX;
-		if (jso->o.c_double <= INT64_MIN)
+		if (jso->o.c_double <= (double)INT64_MIN)
 			return INT64_MIN;
 		return (int64_t)jso->o.c_double;
 	case json_type_boolean: return jso->o.c_boolean;

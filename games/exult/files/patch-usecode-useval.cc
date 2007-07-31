--- usecode/useval.cc.old	2006-10-25 21:43:21.000000000 +0200
+++ usecode/useval.cc	2006-10-25 21:48:49.000000000 +0200
@@ -464,7 +464,7 @@
 		if (buflen < 5)
 			return -1;
 		*ptr++ = type;
-		Write4(ptr, (int)value.ptr);
+		Write4(ptr, 0);
 		break;
 	case string_type:
 		{
@@ -525,7 +525,7 @@
 	case pointer_type:
 		if (buflen < 5)
 			return false;
-		value.ptr = (Game_object*)Read4(ptr); //DON'T dereference this pointer!
+		value.ptr = 0; //DON'T dereference this pointer!
 		// Maybe add a new type "serialized_pointer" to prevent "accidents"?
 		return true;
 	case string_type:

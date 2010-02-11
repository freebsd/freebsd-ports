--- girepository/girnode.c.orig	2009-07-09 21:20:46.000000000 +0400
+++ girepository/girnode.c	2009-12-09 16:12:24.000000000 +0300
@@ -2288,7 +2288,8 @@
 	    break;
 	  case GI_TYPE_TAG_DOUBLE:
 	    blob->size = sizeof (gdouble);
-	    *(gdouble*)&data[blob->offset] = (gdouble) parse_float_value (constant->value);
+	    gdouble tmp = parse_float_value (constant->value);
+	    memcpy (&data[blob->offset], &tmp, blob->size);
 	    break;
 	  case GI_TYPE_TAG_UTF8:
 	  case GI_TYPE_TAG_FILENAME:

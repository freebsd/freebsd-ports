--- girepository/ginfo.c.orig	2010-05-19 02:39:46.000000000 +0000
+++ girepository/ginfo.c	2010-05-30 21:11:54.000000000 +0000
@@ -69,6 +69,9 @@
   const gchar *namespace;
 };
 
+#define DO_ALIGNED_COPY(dest_addr, src_addr, type) \
+	memcpy((dest_addr), (src_addr), sizeof(type))
+
 #define INVALID_REFCOUNT 0x7FFFFFFF
 
 static void
@@ -2349,16 +2352,16 @@
 	      value->v_uint32 = *(guint32*)&rinfo->typelib->data[blob->offset];
 	      break;
 	    case GI_TYPE_TAG_INT64:
-	      value->v_int64 = *(gint64*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_int64, &rinfo->typelib->data[blob->offset], gint64);
 	      break;
 	    case GI_TYPE_TAG_UINT64:
-	      value->v_uint64 = *(guint64*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_uint64, &rinfo->typelib->data[blob->offset], guint64);
 	      break;
 	    case GI_TYPE_TAG_FLOAT:
-	      value->v_float = *(gfloat*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_float, &rinfo->typelib->data[blob->offset], gfloat);
 	      break;
 	    case GI_TYPE_TAG_DOUBLE:
-	      value->v_double = *(gdouble*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_double, &rinfo->typelib->data[blob->offset], gdouble);
 	      break;
 	    case GI_TYPE_TAG_TIME_T:
 	      value->v_long = *(long*)&rinfo->typelib->data[blob->offset];
@@ -2376,10 +2379,10 @@
 	      value->v_uint = *(guint*)&rinfo->typelib->data[blob->offset];
 	      break;
 	    case GI_TYPE_TAG_LONG:
-	      value->v_long = *(glong*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_long, &rinfo->typelib->data[blob->offset], glong);
 	      break;
 	    case GI_TYPE_TAG_ULONG:
-	      value->v_ulong = *(gulong*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_ulong, &rinfo->typelib->data[blob->offset], gulong);
 	      break;
 	    }
 	}

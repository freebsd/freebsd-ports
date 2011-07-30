--- src/sswf/sswf_node.c.orig	2009-03-08 05:04:03.000000000 +0100
+++ src/sswf/sswf_node.c	2011-06-20 23:57:15.000000000 +0200
@@ -2987,65 +2987,65 @@
 
 
 #ifndef _MSVC
-#define	DEF_PARAM(prm, value)		{ param: DEF_PARAM_##prm, { value } }
+#define	DEF_PARAM(prm, value)		{ .param = DEF_PARAM_##prm, { value } }
 
 #define	DEF_START(name)			const struct definition_t node_def_##name[] = {	\
-						DEF_PARAM(NAME, string: #name),
+						DEF_PARAM(NAME, .string = #name),
 
-#define	DEF_END()			DEF_PARAM(END, ignored: 0) };
-#define	DEF_LABEL(label)		DEF_PARAM(LABEL, string: label ),
-#define	DEF_NOLABEL()			DEF_PARAM(LABEL, string: NULL ),
-#define	DEF_REPEAT()			DEF_PARAM(REPEAT, ignored: 0),
-#define	DEF_EMPTY()			DEF_PARAM(EMPTY, ignored: 0),
+#define	DEF_END()			DEF_PARAM(END, .ignored = 0) };
+#define	DEF_LABEL(label)		DEF_PARAM(LABEL, .string = label ),
+#define	DEF_NOLABEL()			DEF_PARAM(LABEL, .string = NULL ),
+#define	DEF_REPEAT()			DEF_PARAM(REPEAT, .ignored = 0),
+#define	DEF_EMPTY()			DEF_PARAM(EMPTY, .ignored = 0),
 
 #define	DEF_OBJECT_REF()								\
-	DEF_PARAM(TYPE, type: NODE_TYPE_OBJECT),					\
-	DEF_PARAM(SUBTYPE, type: NODE_SUBTYPE_REFERENCE),
+	DEF_PARAM(TYPE, .type = NODE_TYPE_OBJECT),					\
+	DEF_PARAM(SUBTYPE, .type = NODE_SUBTYPE_REFERENCE),
 
 #define	DEF_OBJECT(sub_type)								\
-	DEF_PARAM(TYPE, type: NODE_TYPE_DATA),						\
-	DEF_PARAM(SUBTYPE, type: NODE_SUBTYPE_##sub_type),
+	DEF_PARAM(TYPE, .type = NODE_TYPE_DATA),						\
+	DEF_PARAM(SUBTYPE, .type = NODE_SUBTYPE_##sub_type),
 
 #define	DEF_OBJECT_OPT(sub_type)							\
 	DEF_OBJECT(sub_type)								\
-	DEF_PARAM(OPTIONAL, ignored: 0),
+	DEF_PARAM(OPTIONAL, .ignored = 0),
 
 #define	DEF_VALUE0(unit_nm, structure, end_t, field, defval)				\
-	DEF_PARAM(TYPE, type: NODE_TYPE_FLOAT),						\
-	DEF_PARAM(OFFSET, offset: offsetof(struct data_##structure##end_t, field)),	\
-	DEF_PARAM(UNIT, unit: NODE_UNIT_##unit_nm),					\
-	DEF_PARAM(DEFAULT, def_value: defval),
+	DEF_PARAM(TYPE, .type = NODE_TYPE_FLOAT),						\
+	DEF_PARAM(OFFSET, .offset = offsetof(struct data_##structure##end_t, field)),	\
+	DEF_PARAM(UNIT, .unit = NODE_UNIT_##unit_nm),					\
+	DEF_PARAM(DEFAULT, .def_value = defval),
 
 #define	DEF_VALUE(unit, structure, field, def_value)					\
 	DEF_VALUE0(unit, structure, _t, field, def_value)
 
 #define	DEF_VALUE_OPT(unit, structure, field, def_value)				\
 	DEF_VALUE0(unit, structure, _t, field, def_value)				\
-	DEF_PARAM(OPTIONAL, ignored: 0),
+	DEF_PARAM(OPTIONAL, .ignored = 0),
 
 #define	DEF_STRING()									\
-	DEF_PARAM(TYPE, type: NODE_TYPE_STRING),
+	DEF_PARAM(TYPE, .type = NODE_TYPE_STRING),
 
 #define	DEF_STRING_OPT()								\
-	DEF_PARAM(TYPE, type: NODE_TYPE_STRING),					\
-	DEF_PARAM(OPTIONAL, ignored: 0),
+	DEF_PARAM(TYPE, .type = NODE_TYPE_STRING),					\
+	DEF_PARAM(OPTIONAL, .ignored = 0),
 
 #define	DEF_SET0(structure, end_t, field, value)					\
-	DEF_PARAM(SET, set: value),							\
-	DEF_PARAM(OFFSET, offset: offsetof(struct data_##structure##end_t, field)),
+	DEF_PARAM(SET, .set = value),							\
+	DEF_PARAM(OFFSET, .offset = offsetof(struct data_##structure##end_t, field)),
 
 #define	DEF_SET(structure, field, value)						\
 	DEF_SET0(structure, _t, field, value)
 
 #define	DEF_SIZE0(structure, end_t)							\
-	DEF_PARAM(SIZE, size: sizeof(struct data_##structure##end_t)),
+	DEF_PARAM(SIZE, .size =  sizeof(struct data_##structure##end_t)),
 
 #define	DEF_SIZE(structure)								\
 	DEF_SIZE0(structure, _t)
 
 /*
 #define	DEF_SEPARATOR()									\
-	DEF_PARAM(SEPARATOR, ignored: 0),
+	DEF_PARAM(SEPARATOR, .ignored = 0),
 */
 #else
 
@@ -3111,7 +3111,7 @@
 
 #define	DEF_START(name)				DEF_PARAM(string, node_def_##name, NAME, #name)
 
-//const struct definition_t node_def_##name[] = { DEF_PARAM(NAME, string: #name),
+//const struct definition_t node_def_##name[] = { DEF_PARAM(NAME, .string = #name),
 
 #define	DEF_END()			DEF_PARAM_IGNORE(END)
 #define	DEF_LABEL(label)		DEF_PARAM_AN(string, LABEL, label)
@@ -3166,7 +3166,7 @@
 
 /*
 #define	DEF_SEPARATOR()									\
-	DEF_PARAM(SEPARATOR, ignored: 0),
+	DEF_PARAM(SEPARATOR, .ignored = 0),
 */
 #endif
 

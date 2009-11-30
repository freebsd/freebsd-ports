--- python/core/conversions.sip
+++ python/core/conversions.sip
@@ -28,6 +28,10 @@
 {
 %TypeHeaderCode
 #include <QVector>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -104,6 +108,10 @@
 {
 %TypeHeaderCode
 #include <QVector>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -179,6 +187,10 @@
 {
 %TypeHeaderCode
 #include <QSet>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -229,6 +241,10 @@
 {
 %TypeHeaderCode
 #include <QSet>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -301,6 +317,10 @@
 {
 %TypeHeaderCode
 #include <QMap>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -418,6 +438,10 @@
 {
 %TypeHeaderCode
 #include <QMap>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -518,7 +542,11 @@
 %MappedType QMap<TYPE1, TYPE2*>
 {
 %TypeHeaderCode
-#include <qmap.h>
+#include <QMap>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -626,6 +654,10 @@
 {
 %TypeHeaderCode
 #include <QMultiMap>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode
@@ -744,6 +776,10 @@
 {
 %TypeHeaderCode
 #include <QMap>
+#if (SIP_VERSION >= 0x040900)
+#define sipClass_QString ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QString))
+#define sipClass_QVariant ((sipWrapperType *) sipTypeAsPyTypeObject (sipType_QVariant))
+#endif
 %End
 
 %ConvertFromTypeCode

https://gitlab.xiph.org/xiph/libopusenc/-/commit/04c6172ffbbd5c7f7f2e170cf843872113f33b05

--- include/opusenc.h.orig	2018-09-14 17:12:05 UTC
+++ include/opusenc.h
@@ -121,6 +121,13 @@ extern "C" {
 #define OPE_GET_NB_STREAMS_REQUEST          14013
 #define OPE_GET_NB_COUPLED_STREAMS_REQUEST  14015
 
+/* Macros to trigger compilation errors when the wrong types are provided to a CTL. */
+/* These macros are not part of the API and are only for use within the macros below. */
+#define ope_check_int(x) (((void)((x) == (opus_int32)0)), (opus_int32)(x))
+#define ope_check_int_ptr(ptr) ((ptr) + ((ptr) - (opus_int32*)(ptr)))
+#define ope_check_packet_func(x) ((void)((void (*)(void *, const unsigned char *, opus_int32, opus_uint32))0 == (x)), (x))
+#define ope_check_void_ptr(x) ((void)((void *)0 == (x)), (x))
+
 /**\defgroup encoder_ctl Encoding Options*/
 /*@{*/
 
@@ -129,21 +136,20 @@ extern "C" {
    Macros for setting encoder options.*/
 /*@{*/
 
-#define OPE_SET_DECISION_DELAY(x) OPE_SET_DECISION_DELAY_REQUEST, __opus_check_int(x)
-#define OPE_GET_DECISION_DELAY(x) OPE_GET_DECISION_DELAY_REQUEST, __opus_check_int_ptr(x)
-#define OPE_SET_MUXING_DELAY(x) OPE_SET_MUXING_DELAY_REQUEST, __opus_check_int(x)
-#define OPE_GET_MUXING_DELAY(x) OPE_GET_MUXING_DELAY_REQUEST, __opus_check_int_ptr(x)
-#define OPE_SET_COMMENT_PADDING(x) OPE_SET_COMMENT_PADDING_REQUEST, __opus_check_int(x)
-#define OPE_GET_COMMENT_PADDING(x) OPE_GET_COMMENT_PADDING_REQUEST, __opus_check_int_ptr(x)
-#define OPE_SET_SERIALNO(x) OPE_SET_SERIALNO_REQUEST, __opus_check_int(x)
-#define OPE_GET_SERIALNO(x) OPE_GET_SERIALNO_REQUEST, __opus_check_int_ptr(x)
-/* FIXME: Add type-checking macros to these. */
-#define OPE_SET_PACKET_CALLBACK(x,u) OPE_SET_PACKET_CALLBACK_REQUEST, (x), (u)
+#define OPE_SET_DECISION_DELAY(x) OPE_SET_DECISION_DELAY_REQUEST, ope_check_int(x)
+#define OPE_GET_DECISION_DELAY(x) OPE_GET_DECISION_DELAY_REQUEST, ope_check_int_ptr(x)
+#define OPE_SET_MUXING_DELAY(x) OPE_SET_MUXING_DELAY_REQUEST, ope_check_int(x)
+#define OPE_GET_MUXING_DELAY(x) OPE_GET_MUXING_DELAY_REQUEST, ope_check_int_ptr(x)
+#define OPE_SET_COMMENT_PADDING(x) OPE_SET_COMMENT_PADDING_REQUEST, ope_check_int(x)
+#define OPE_GET_COMMENT_PADDING(x) OPE_GET_COMMENT_PADDING_REQUEST, ope_check_int_ptr(x)
+#define OPE_SET_SERIALNO(x) OPE_SET_SERIALNO_REQUEST, ope_check_int(x)
+#define OPE_GET_SERIALNO(x) OPE_GET_SERIALNO_REQUEST, ope_check_int_ptr(x)
+#define OPE_SET_PACKET_CALLBACK(x,u) OPE_SET_PACKET_CALLBACK_REQUEST, ope_check_packet_func(x), ope_check_void_ptr(u)
 /*#define OPE_GET_PACKET_CALLBACK(x,u) OPE_GET_PACKET_CALLBACK_REQUEST, (x), (u)*/
-#define OPE_SET_HEADER_GAIN(x) OPE_SET_HEADER_GAIN_REQUEST, __opus_check_int(x)
-#define OPE_GET_HEADER_GAIN(x) OPE_GET_HEADER_GAIN_REQUEST, __opus_check_int_ptr(x)
-#define OPE_GET_NB_STREAMS(x) OPE_GET_NB_STREAMS_REQUEST, __opus_check_int_ptr(x)
-#define OPE_GET_NB_COUPLED_STREAMS(x) OPE_GET_NB_COUPLED_STREAMS_REQUEST, __opus_check_int_ptr(x)
+#define OPE_SET_HEADER_GAIN(x) OPE_SET_HEADER_GAIN_REQUEST, ope_check_int(x)
+#define OPE_GET_HEADER_GAIN(x) OPE_GET_HEADER_GAIN_REQUEST, ope_check_int_ptr(x)
+#define OPE_GET_NB_STREAMS(x) OPE_GET_NB_STREAMS_REQUEST, ope_check_int_ptr(x)
+#define OPE_GET_NB_COUPLED_STREAMS(x) OPE_GET_NB_COUPLED_STREAMS_REQUEST, ope_check_int_ptr(x)
 /*@}*/
 /*@}*/
 

--- third_party/libva_protected_content/va_protected_content.h.orig	2021-04-14 01:09:37 UTC
+++ third_party/libva_protected_content/va_protected_content.h
@@ -133,6 +133,7 @@ extern "C" {
 #define VA_PC_SAMPLE_TYPE_SUBSAMPLE 0x00000002
 
 /** \brief TeeExec Function Codes. */
+#if 0
 typedef enum _VA_TEE_EXEC_FUNCTION_ID {
   VA_TEE_EXEC_TEE_FUNCID_PASS_THROUGH_NONE = 0x0,
 
@@ -144,6 +145,7 @@ typedef enum _VA_TEE_EXEC_FUNCTION_ID {
   VA_TEE_EXEC_TEE_FUNCID_PASS_THROUGH = 0x40001000,
 
 } VA_TEE_EXEC_FUNCTION_ID;
+#endif
 
 /** \brief values for the encryption return status. */
 typedef enum {
@@ -160,6 +162,7 @@ typedef enum {
 } VAEncryptionStatus;
 
 /** \brief structure for encrypted segment info. */
+#if 0
 typedef struct _VAEncryptionSegmentInfo {
   /** \brief  The offset relative to the start of the bitstream input in
    *  bytes of the start of the segment*/
@@ -215,6 +218,7 @@ typedef struct _VAEncryptionParameters {
   /** \brief Reserved bytes for future use, must be zero */
   uint32_t va_reserved[VA_PADDING_MEDIUM];
 } VAEncryptionParameters;
+#endif
 
 /** \brief structure for VA_TEE_EXEC_GPU_FUNCID_ENCRYPTION_BLT */
 typedef struct _VA_PROTECTED_BLT_PARAMS {

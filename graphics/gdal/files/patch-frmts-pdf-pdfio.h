Obtained from:	https://github.com/OSGeo/gdal/commit/783addc36d7da7a3f0c15fd46dde117e0ec0bb87

--- frmts/pdf/pdfio.h.orig	2019-03-15 12:33:01 UTC
+++ frmts/pdf/pdfio.h
@@ -93,11 +93,6 @@ class VSIPDFFileStream final: public Bas
         virtual void       close() override;
 
     private:
-        /* getChars/hasGetChars added in poppler 0.15.0
-         * POPPLER_BASE_STREAM_HAS_TWO_ARGS true from poppler 0.16,
-         * This test will be wrong for poppler 0.15 or 0.16,
-         * but will still compile correctly.
-         */
         virtual GBool hasGetChars() override;
         virtual int getChars(int nChars, Guchar *buffer) override;
 

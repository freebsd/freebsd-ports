--- lib/qwavheader.hh.orig	Fri Feb 23 21:29:12 2001
+++ lib/qwavheader.hh	Fri Feb 13 19:17:38 2004
@@ -20,9 +20,11 @@
    /*! 
     * \brief struct for wav headers
     *
-    * this struct is defined to match exactly with a 'canonical' wav header with no change on a little-endian machine
+    * this struct is defined to match exactly with a 'canonical' wav header with no
+	* change on a little-endian machine; on other architectures the alignment will
+	* match but int values will need conversion
     */
-    struct header {
+    struct wavheader {
 
      // riff chunk
       char riff[4];		/*!< should be 'RIFF' */
@@ -41,10 +43,19 @@
     
       char data[4];		/*!< should be 'data' */
       u_int32_t datalength;	/*!< data block length (file size - 44) */
-    };
+
+	  wavheader(caddr_t p) { headerCopy(p); }
+
+	  /*!
+	   * Copies WAV header from little-endian to host order
+	   * \param p the memory address where the header is located
+	   * \param nativeendian whether the struct is already in native byte ordering
+	   */
+	  void headerCopy(caddr_t p);
+    } __attribute__ ((__packed__));
 
    //! pointer to the header (memory location where it is located)
-    struct header *header;
+  wavheader *header, *mappedheader;
 
   public:
 
@@ -58,6 +69,15 @@
     */
     qwavheader (caddr_t p, u_int32_t length=0);
 
+    /*! deep-copy */
+    qwavheader (const qwavheader& qwh)
+	  :header(new wavheader(*qwh.header)), mappedheader(qwh.mappedheader) {}
+
+   /*!
+   * releases storage allocated for header
+   */
+  ~qwavheader();
+
    /*!
     * \brief gets the number of samples
     * \return the number of samples
@@ -147,11 +167,6 @@
     * \return whether is valid or not
     */
     bool validLength(u_int32_t length);
-   /*!
-    * \brief write (copy) the header to the given address
-    * \param a the memory address where to write the header
-    */
-    void write(caddr_t );
 };
 
 # endif

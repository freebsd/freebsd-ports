--- lib/tobjstrm.h.orig	2001-07-29 22:28:47.000000000 +0200
+++ lib/tobjstrm.h	2008-07-27 18:54:38.000000000 +0200
@@ -1,5 +1,5 @@
-/*
- * tobjstrm.h
+/**
+ * @file tobjstrm.h
  *
  * Turbo Vision - Version 2.0
  *
@@ -7,11 +7,14 @@
  * All Rights Reserved.
  *
  * Modified by Sergio Sigala <sergio@sigala.it>
+ * Modified by Max Okumoto <okumoto@ucsd.edu>
  */
 
-/** \file tobjstrm.h
- * tobjstrm.h
- */
+#include <ios>
+#include <iostream>
+#include <fstream>
+
+#include <limits.h>
 
 /**
  * Undocumented.
@@ -19,13 +22,11 @@
 typedef unsigned P_id_type;
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class TStreamable                                                     */
 /*                                                                         */
 /*   This is the base class for all storable objects.  It provides         */
 /*   three member functions, streamableName(), read(), and write(), which  */
 /*   must be overridden in every derived class.                            */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if !defined( __fLink_def )
@@ -117,18 +118,12 @@
 #endif  // Uses_TStreamable
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class TStreamableClass                                                */
-/*                                                                         */
-/*   Used internally by TStreamableTypes and pstream.                      */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_TStreamableClass ) && !defined( __TStreamableClass )
 #define __TStreamableClass
 
-#include <limits.h>
-
 /**
  * Undocumented.
  */
@@ -144,7 +139,7 @@
  */
 typedef TStreamable *(*BUILDER)();
 
-#define __DELTA( d ) ((int)(TStreamable*)(d*)1-1 )
+#define __DELTA( d ) ((intptr_t)(TStreamable*)(d*)1-1 )
 
 /**
  * TStreamableClass is used by @ref TStreamableTypes and @ref pstream in the
@@ -154,9 +149,9 @@
  */
 class TStreamableClass
 {
-    friend TStreamableTypes;
-    friend opstream;
-    friend ipstream;
+    friend class TStreamableTypes;
+    friend class opstream;
+    friend class ipstream;
 public:
     /**
      * Creates a TStreamable object with the given name and the given builder
@@ -184,7 +179,7 @@
      * typedef TStreamable *(*BUILDER)();
      * </pre>
      */
-    TStreamableClass( const char *aName, BUILDER aBuild, int aDelta );
+    TStreamableClass(const char *aName, BUILDER aBuild, int aDelta );
 private:
     const char *name;
     BUILDER build;
@@ -194,13 +189,7 @@
 #endif  // Uses_TStreamableClass
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class TStreamableTypes                                                */
-/*                                                                         */
-/*   Maintains a database of all registered types in the application.      */
-/*   Used by opstream and ipstream to find the functions to read and       */
-/*   write objects.                                                        */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_TStreamableTypes ) && !defined( __TStreamableTypes )
@@ -235,20 +224,12 @@
     /**
      * Registers the argument class by inserting `d' in the collection.
      */
-    void registerType( const TStreamableClass *d );
+    void registerType(const TStreamableClass *d );
     /**
      * Returns a pointer to the class in the collection corresponding to the
      * argument `name', or returns 0 if no match.
      */
-    const TStreamableClass *lookup( const char *name );
-    /**
-     * Undocumented.
-     */
-    void *operator new( size_t sz ) { return ::operator new( sz ); }
-    /**
-     * Undocumented.
-     */
-    void *operator new( size_t, void * );
+    const TStreamableClass *lookup(const char name[]);
 private:
     /**
      * Undocumented.
@@ -263,15 +244,7 @@
 #endif  // Uses_TStreamableTypes
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class TPWrittenObjects                                                */
-/*                                                                         */
-/*   Maintains a database of all objects that have been written to the     */
-/*   current object stream.                                                */
-/*                                                                         */
-/*   Used by opstream when it writes a pointer onto a stream to determine  */
-/*   whether the object pointed to has already been written to the stream. */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_TPWrittenObjects ) && !defined( __TPWrittenObjects )
@@ -286,7 +259,7 @@
  */
 class TPWrittenObjects : public TNSSortedCollection
 {
-    friend opstream;
+    friend class opstream;
 public:
     /**
      * Undocumented.
@@ -306,11 +279,11 @@
     /**
      * Undocumented.
      */
-    void registerObject( const void *adr );
+    void registerObject(const void *adr );
     /**
      * Undocumented.
      */
-    P_id_type find( const void *adr );
+    P_id_type find(const void *adr );
     /**
      * Undocumented.
      */
@@ -326,11 +299,7 @@
 };
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class TPWObj                                                          */
-/*                                                                         */
-/*   Used internally by TPWrittenObjects.                                  */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 /**
@@ -341,9 +310,9 @@
  */
 class TPWObj
 {
-    friend TPWrittenObjects;
+    friend class TPWrittenObjects;
 private:
-    TPWObj( const void *adr, P_id_type id );
+    TPWObj(const void *adr, P_id_type id );
     const void *address;
     P_id_type ident;
 };
@@ -351,15 +320,7 @@
 #endif  // Uses_TPWrittenObjects
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class TPReadObjects                                                   */
-/*                                                                         */
-/*   Maintains a database of all objects that have been read from the      */
-/*   current persistent stream.                                            */
-/*                                                                         */
-/*   Used by ipstream when it reads a pointer from a stream to determine   */
-/*   the address of the object being referred to.                          */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_TPReadObjects ) && !defined( __TPReadObjects )
@@ -375,7 +336,7 @@
  */
 class TPReadObjects : public TNSCollection
 {
-    friend ipstream;
+    friend class ipstream;
 public:
     /**
      * Undocumented.
@@ -393,7 +354,7 @@
      * Sets the collection @ref limit to 0 without destroying the collection.
      */
     ~TPReadObjects();
-    void registerObject( const void *adr );
+    void registerObject(const void *adr );
     const void *find( P_id_type id );
     P_id_type curId;
 };
@@ -401,164 +362,62 @@
 #endif  // Uses_TPReadObjects
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class pstream                                                         */
-/*                                                                         */
-/*   Base class for handling streamable objects.                           */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_pstream ) && !defined( __pstream )
 #define __pstream
 
-class streambuf;
-
-#include <iostream.h>
-
 class TStreamableTypes;
 
 /**
  * pstream is the base class for handling streamable objects.
  * @short The base class for handling streamable objects
  */
-class pstream
-{
-    friend TStreamableTypes;
+class pstream {
+protected:
+    /**
+     * Pointer to the @ref TStreamableTypes data base of all registered types
+     * in this application.
+     */
+    static TStreamableTypes *types;
+
 public:
+    pstream();
+    virtual ~pstream();
+
     /**
      * Undocumented.
      */
     enum StreamableError { peNotRegistered, peInvalidType };
+
     /**
      * Undocumented.
      */
     enum PointerTypes { ptNull, ptIndexed, ptObject };
-    /**
-     * This form creates a buffered pstream with the given buffer and sets the
-     * @ref bp data member to `buf'. The @ref state data member is set to 0.
-     */
-    pstream( streambuf *buf );
-    /**
-     * Destroys the pstream object.
-     */
-    virtual ~pstream();
-    /**
-     * Returns the current @ref state value.
-     */
-    int rdstate() const;
-    /**
-     * Returns nonzero on end of stream.
-     */
-    int eof() const;
-    /**
-     * Returns nonzero if a stream operation fails.
-     */
-    int fail() const;
-    /**
-     * Returns nonzero if an error occurs.
-     */
-    int bad() const;
-    /**
-     * Returns nonzero if no state bits are set (that is, no errors occurred).
-     */
-    int good() const;
-    /**
-     * Set the stream @ref state data member to the given value (defaults
-     * to 0).
-     */
-    void clear( int sState = 0 );
-    /**
-     * Overloads the pointer-to-void cast operator.
-     *
-     * Returns 0 if operation has failed (that is, @ref fail() returned
-     * nonzero); otherwise returns nonzero.
-     */
-    operator void *() const;
-    /**
-     * Overloads the NOT operator. Returns the value returned by @ref fail().
-     */
-    int operator ! () const;
-    /**
-     * Returns the @ref bp pointer to this stream's assigned buffer.
-     */
-    streambuf * rdbuf() const;
-    /**
-     * Creates the associated @ref TStreamableTypes object types. Called by the
-     * @ref TStreamableClass constructor.
-     */
+
+    void error(StreamableError);
+    void error(StreamableError, const TStreamable &);
+
     static void initTypes();
-    /**
-     * Sets the given error condition, where StreamableError is defined as
-     * follows:
-     *
-     * <pre>
-     * enum StreamableError { peNotRegistered, peInvalidType };
-     * </pre>
-     */
-    void error( StreamableError );
-    /**
-     * Sets the given error condition, where StreamableError is defined as
-     * follows:
-     *
-     * <pre>
-     * enum StreamableError { peNotRegistered, peInvalidType };
-     * </pre>
-     */
-    void error( StreamableError, const TStreamable& );
-    /**
-     * Undocumented.
-     */
-    static void registerType( TStreamableClass *ts );
-protected:
-    /**
-     * This form allocates a default buffer.
-     */
-    pstream();
-    /**
-     * Pointer to the stream buffer.
-     */
-    streambuf *bp;
-    /**
-     * The format state flags, as enumerated in ios. Use @ref rdstate() to
-     * access the current state.
-     */
-    int state;
-    /**
-     * Initializes the stream: sets @ref state to 0 and @ref bp to `sbp'.
-     */
-    void init( streambuf *sbp );
-    /**
-     * Updates the @ref state data member with state |= (b & 0 xFF).
-     */
-    void setstate( int b );
-    /**
-     * Pointer to the @ref TStreamableTypes data base of all registered types
-     * in this application.
-     */
-    static TStreamableTypes * types;
+    static void registerType(TStreamableClass *ts);
 };
 
 #endif  // Uses_pstream
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class ipstream                                                        */
-/*                                                                         */
-/*   Base class for reading streamable objects                             */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_ipstream ) && !defined( __ipstream )
 #define __ipstream
 
-#include <iostream.h>
-
 class TStreamableClass;
 
 /**
  * ipstream, a specialized input stream derivative of @ref pstream, is the
  * base class for reading (extracting) streamable objects. ipstream is
- * analogous to istream, defined in `iostream.h' for the standard C++ stream
+ * analogous to istream, defined in `iostream' for the standard C++ stream
  * library. ipstream is a friend class of @ref TPReadObjects.
  *
  * The overloaded operators >> extract (read) from the given ipstream object
@@ -566,176 +425,69 @@
  * to chain >> operations in the usual way. The data type of the argument
  * determines how the read is performed. For example, reading a signed char
  * is implemented using @ref readByte().
+ *
  * @see opstream
+ *
  * @short The base class for reading (extracting) streamable objects from
  * streams
  */
-class ipstream : virtual public pstream
-{
-public:
-    /**
-     * This form creates a buffered ipstream with the given buffer and sets
-     * the @ref bp data member to `buf'. The @ref state data member is set
-     * to 0.
-     */
-    ipstream( streambuf *buf );
-    /**
-     * Destroys the ipstream object.
-     */
-    ~ipstream();
-    /**
-     * Returns the (absolute) current stream position.
-     */
-    streampos tellg();
-    /**
-     * This form moves the stream position to the absolute position given by
-     * `pos'.
-     */
-    ipstream& seekg( streampos pos );
-    /**
-     * This form moves to a position relative to the current position by an
-     * offset `off' (+ or -) starting at `dir'. Parameter `dir' can be set to:
-     *
-     * <pre>
-     * beg (start of stream)
-     *
-     * cur (current stream position)
-     *
-     * end (end of stream)
-     * </pre>
-     */
-    ipstream& seekg( streamoff off, ios::seek_dir dir );
-    /**
-     * Returns the character at the current stream position.
-     */
-    uchar readByte();
-    /**
-     * Reads `sz' bytes from current stream position, and writes them to
-     * the address given in `data'.
-     */
-    void readBytes( void *data, size_t sz );
-    /**
-     * Returns the word at the current stream position.
-     */
-    ushort readWord();
-    /**
-     * Returns a string read from the current stream position.
-     */
-    char * readString();
-    /**
-     * Returns a string read from the current stream position.
-     */
-    char * readString( char *buf, unsigned maxLen );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, char& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, signed char& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, unsigned char& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, signed short& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, unsigned short& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, signed int& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, unsigned int& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, signed long& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, unsigned long& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, float& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, double& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, long double& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, TStreamable& );
-    /**
-     * Undocumented.
-     */
-    friend ipstream& operator >> ( ipstream&, void *& );
-protected:
-    /**
-     * This form does nothing.
-     */
-    ipstream();
-    /**
-     * Returns the @ref TStreamableClass object corresponding to the class
-     * name stored at the current position.
-     */
-    const TStreamableClass * readPrefix();
-    /**
-     * Invokes the appropriate read function to read from the stream to the
-     * object `mem'. If `mem' is 0, the appropriate build function is called
-     * first.
-     */
-    void * readData( const TStreamableClass *c, TStreamable *mem );
-    /**
-     * Reads and checks the final byte of an object's name field.
-     */
-    void readSuffix();
-    /**
-     * Returns a pointer to the object corresponding to `id'.
-     */
-    const void * find( P_id_type id );
-    /**
-     * Registers the class of the object pointed by `adr'.
-     */
-    void registerObject( const void *adr );
+class ipstream : virtual public pstream, public std::istream {
 private:
     TPReadObjects objs;
 
+protected:
+    const TStreamableClass *readPrefix();
+    void *readData(const TStreamableClass *c, TStreamable *mem);
+    void readSuffix();
+    const void	*find(P_id_type id);
+    void registerObject(const void *adr);
+
+    ushort readWord();
+    ulong readLong();
+
+public:
+    ipstream(std::streambuf *buf);
+    ~ipstream();
+
+    ipstream &seekg(std::streampos pos);
+    ipstream &seekg(std::streamoff off, std::ios::seekdir dir);
+
+    uchar readByte();
+    void readBytes(void *data, std::streamsize sz);
+    char *readString();
+    char *readString(char *buf, unsigned maxLen);
+
+    ipstream &operator>>(char &);
+    ipstream &operator>>(signed char &);
+    ipstream &operator>>(unsigned char &);
+    ipstream &operator>>(signed short &);
+    ipstream &operator>>(unsigned short &);
+    ipstream &operator>>(signed int &);
+    ipstream &operator>>(unsigned int &);
+    ipstream &operator>>(signed long &);
+    ipstream &operator>>(unsigned long &);
+    ipstream &operator>>(float &);
+    ipstream &operator>>(double &);
+    ipstream &operator>>(long double &);
+    ipstream &operator>>(TStreamable &);
+    ipstream &operator>>(void *&);
 };
 
 #endif  // Uses_ipstream
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class opstream                                                        */
-/*                                                                         */
-/*   Base class for writing streamable objects                             */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_opstream ) && !defined( __opstream )
 #define __opstream
 
-#include <iostream.h>
-
 class TStreamableClass;
 
 /**
  * opstream, a specialized output stream derivative of @ref pstream, is the
  * base class for writing (inserting) streamable objects. opstream is
- * analogous to ostream, defined in `iostream.h' for the standard C++ stream
+ * analogous to ostream, defined in `iostream' for the standard C++ stream
  * library. opstream is a friend class of @ref TPWrittenObjects.
  *
  * The overloaded operators << insert (write) the given argument to the given
@@ -743,469 +495,146 @@
  * to chain << operations in the usual way. The data type of the argument
  * determines the form of write operation employed. For example, writing a
  * signed char is implemented using @ref writeByte().
+ *
  * @see ipstream
+ *
  * @short The base class for writing (inserting) streamable objects into
  * streams
  */
-class opstream : virtual public pstream
-{
+class opstream : virtual public pstream, public std::ostream {
+    TPWrittenObjects objs;
+
+protected:
+    void writePrefix(const TStreamable &);
+    void writeData(TStreamable &);
+    void writeSuffix(const TStreamable &);
+    P_id_type find(const void *adr);
+    void registerObject(const void *adr);
+
 public:
-    /**
-     * This form creates a buffered opstream with the given buffer and sets
-     * the @ref bp data member to `buf'. The @ref state data member is set
-     * to 0.
-     */
-    opstream( streambuf *buf );
-    /**
-     * Destroys the opstream object.
-     */
+    opstream(std::streambuf *buf);
     ~opstream();
-    /**
-     * Returns the (absolute) current stream position.
-     */
-    streampos tellp();
-    /**
-     * This form moves the stream's current position to the absolute position
-     * given by `pos'.
-     */
-    opstream& seekp( streampos pos );
-    /**
-     * This form moves to a position relative to the current position by an
-     * offset `off' (+ or -) starting at `dir'. Parameter `dir' can be set to:
-     *
-     * <pre>
-     * beg (start of stream)
-     *
-     * cur (current stream position)
-     *
-     * end (end of stream)
-     * </pre>
-     */
-    opstream& seekp( streamoff off, ios::seek_dir dir );
-    /**
-     * Flushes the stream.
-     */
+    opstream& seekp(std::streampos pos);
+    opstream& seekp(std::streamoff off, std::ios::seekdir dir);
     opstream& flush();
-    /**
-     * Writes character `ch' to the stream.
-     */
-    void writeByte( uchar ch );
-    /**
-     * Writes `sz' bytes from `data' buffer to the stream.
-     */
-    void writeBytes( const void *data, size_t sz );
-    /**
-     * Writes the word `us' to the stream.
-     */
-    void writeWord( ushort us );
-    /**
-     * Writes `str' to the stream (together with a leading length byte).
-     */
-    void writeString( const char *str );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, char );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, signed char );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, unsigned char );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, signed short );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, unsigned short );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, signed int );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, unsigned int );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, signed long );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, unsigned long );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, float );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, double );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, long double );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, TStreamable& );
-    /**
-     * Undocumented.
-     */
-    friend opstream& operator << ( opstream&, TStreamable * );
-protected:
-    /**
-     * This form allocates a default buffer.
-     */
-    opstream();
-    /**
-     * Writes the class name prefix to the stream.
-     *
-     * The << operator uses this function to write a prefix and suffix around
-     * the data written with @ref writeData(). The prefix/suffix is used to
-     * ensure type-safe stream I/O.
-     */
-    void writePrefix( const TStreamable& );
-    /**
-     * Writes data to the stream by calling the appropriate class's write
-     * member function for the object being written.
-     */
-    void writeData( TStreamable& );
-    /**
-     * Writes the class name suffix to the stream.
-     *
-     * The << operator uses this function to write a prefix and suffix around
-     * the data written with @ref writeData(). The prefix/suffix is used to
-     * ensure type-safe stream I/O.
-     */
-    void writeSuffix( const TStreamable& );
-    /**
-     * Returns the type ID for the object ad address `adr'.
-     */
-    P_id_type find( const void *adr );
-    /**
-     * Registers the class of the object ad address `adr'.
-     */
-    void registerObject( const void *adr );
-private:
-    TPWrittenObjects *objs;
+
+    void writeByte(uchar ch);
+    void writeBytes(const void *data, std::streamsize sz);
+    void writeWord(ushort us);
+    void writeString(const char *str);
+
+    opstream &operator<<(char);
+    opstream &operator<<(signed char);
+    opstream &operator<<(unsigned char);
+    opstream &operator<<(signed short);
+    opstream &operator<<(unsigned short);
+    opstream &operator<<(signed int);
+    opstream &operator<<(unsigned int);
+    opstream &operator<<(signed long);
+    opstream &operator<<(unsigned long);
+    opstream &operator<<(float);
+    opstream &operator<<(double);
+    opstream &operator<<(long double);
+    opstream &operator<<(TStreamable &);
+    opstream &operator<<(TStreamable *);
 };
 
 #endif  // Uses_opstream
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class iopstream                                                       */
-/*                                                                         */
-/*   Base class for reading and writing streamable objects                 */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_iopstream ) && !defined( __iopstream )
 #define __iopstream
 
-#include <iostream.h>
-
 /**
  * Class iopstream is a simple "mix" of its bases, @ref opstream and
  * @ref ipstream. It provides the base class for simultaneous writing and
  * reading streamable objects.
+ *
  * @short The base class for simultaneous writing and reading streamable
  * objects to and from streams
  */
-class iopstream : public ipstream, public opstream
-{
+class iopstream : public ipstream, public opstream {
 public:
-    /**
-     * Creates a buffered iopstream with the given buffer and sets the @ref bp
-     * data member to `buf'. The @ref state data member is set to 0.
-     */
-    iopstream( streambuf *buf );
-    /**
-     * Destroys the iopstream object.
-     */
+    iopstream(std::streambuf *buf);
     ~iopstream();
-protected:
-    /**
-     * Undocumented.
-     */
-    iopstream();
 };
 
 #endif  // Uses_iopstream
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
-/*   class fpbase                                                          */
-/*                                                                         */
-/*   Base class for handling streamable objects on file streams            */
-/*                                                                         */
-/* ------------------------------------------------------------------------*/
-
-#if defined( Uses_fpbase ) && !defined( __fpbase )
-#define __fpbase
-
-#include <fstream.h>
-
-/**
- * fpbase provides the basic operations common to all object file stream I/O.
- * @short Base class for handling streamable objects on file streams
- */
-class fpbase : virtual public pstream
-{
-public:
-    /**
-     * Creates a buffered fpbase object.
-     */
-    fpbase();
-    /**
-     * Creates a buffered fpbase object. You can open a file and attach it to
-     * the stream by specifying the `name', `omode', and `prot' (protection)
-     * arguments.
-     */
-    fpbase( const char *name, int omode, int prot = filebuf::openprot );
-    /**
-     * Creates a buffered fpbase object. You can open a file and attach it to
-     * the stream by specifying the file descriptor, `f'.
-     */
-    fpbase( int f );
-    /**
-     * Creates a buffered fpbase object. You can set the size and initial
-     * contents of the buffer with the `len' and `b' arguments. You can open
-     * a file and attach it to the stream by specifying the file descriptor,
-     * `f'.
-     */
-    fpbase( int f, char *b, int len);
-    /**
-     * Destroys the fpbase object.
-     */
-    ~fpbase();
-    /**
-     * Opens the named file in the given mode (app, ate, in, out, binary,
-     * trunc, nocreate, noreplace) and protection. The opened file is
-     * attached to this stream.
-     */
-    void open( const char *name, int omode, int prot = filebuf::openprot );
-    /**
-     * Attaches the file with descriptor `f' to this stream if possible.
-     */
-    void attach( int f );
-    /**
-     * Closes the stream and associated file.
-     */
-    void close();
-    /**
-     * Allocates a buffer of size `len'.
-     */
-    void setbuf( char *buf, int len );
-    /**
-     * Returns a pointer to the current file buffer.
-     */
-    filebuf * rdbuf();
-private:
-    filebuf buf;
-};
-
-#endif  // Uses_fpbase
-
-/* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class ifpstream                                                       */
-/*                                                                         */
-/*   Base class for reading streamable objects from file streams           */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_ifpstream ) && !defined( __ifpstream )
 #define __ifpstream
 
-#include <iostream.h>
-
 /**
- * ifpstream is a simple "mix" of its bases, @ref fpbase and @ref ipstream.
- * It provides the base class for reading (extracting) streamable objects
- * from file streams.
- * @short Provides the base class for reading (extracting) streamable objects
+ * ifpstream provides the base class for reading (extracting)
+ * streamable objects from file streams.
+ *
+ * @short The base class for reading (extracting) streamable objects
  * from file streams.
  */
-class ifpstream : public fpbase, public ipstream
-{
+class ifpstream : public ipstream {
+    std::filebuf	buf;
 public:
-    /**
-     * Creates a buffered ifpstream object.
-     */
     ifpstream();
-    /**
-     * Creates a buffered ifpstream object. You can open a file and attach it
-     * to the stream by specifying the `name', `omode', and `prot'
-     * (protection) arguments.
-     */
-    ifpstream(const char *name, int omode = ios::in,
-        int prot = filebuf::openprot );
-    /**
-     * Creates a buffered ifpstream object. You can open a file and attach it
-     * to the stream by specifying the file descriptor, `f'.
-     */
-    ifpstream( int f );
-    /**
-     * Creates a buffered ifpstream object. You can set the size and initial
-     * contents of the buffer with the `len' and `b' arguments. You can open
-     * a file and attach it to the stream by specifying the file descriptor,
-     * `f'.
-     */
-    ifpstream( int f, char *b, int len );
-    /**
-     * Destroys the ifpstream object.
-     */
+    ifpstream(const char name[], std::ios::openmode omode = std::ios::in);
     ~ifpstream();
-    /**
-     * Returns a pointer to the current file buffer.
-     */
-    filebuf * rdbuf();
-    /**
-     * Opens the the named file in the given mode (app, ate, in, out, binary,
-     * trunc, nocreate, or noreplace) and protection. The default mode is in
-     * (input) with openprot protection. The opened file is attached to this
-     * stream.
-     */
-    void open( const char *name, int omode = ios::in,
-        int prot = filebuf::openprot );
+    void open(const char name[], std::ios::openmode omode = std::ios::in);
 };
 
 #endif  // Uses_ifpstream
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class ofpstream                                                       */
-/*                                                                         */
-/*   Base class for writing streamable objects to file streams             */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_ofpstream ) && !defined( __ofpstream )
 #define __ofpstream
 
-#include <iostream.h>
-
 /**
- * Class ofpstream is a simple "mix" of its bases, @ref fpbase and
- * @ref opstream. It provides the base class for writing (inserting)
+ * ofpstream provides the base class for writing (inserting)
  * streamable objects to file streams.
- * @short Provides the base class for writing (inserting) streamable objects
- * to file streams
+ *
+ * @short The base class for writing (inserting) streamable objects
+ * to file streams.
  */
-class ofpstream : public fpbase, public opstream
-{
+class ofpstream : public opstream {
+    std::filebuf	buf;
 public:
-    /**
-     * Creates a buffered ofpstream object.
-     */
     ofpstream();
-    /**
-     * Creates a buffered ofpstream object. You can open a file and attach it
-     * to the stream by specifying the `name', `omode', and `prot'
-     * (protection) arguments.
-     */
-    ofpstream( const char *name, int omode = ios::out, int prot =
-        filebuf::openprot );
-    /**
-     * Creates a buffered ofpstream object. You can open a file and attach it
-     * to the stream by specifying the file descriptor, `f'.
-     */
-    ofpstream( int f );
-    /**
-     * Creates a buffered ofpstream object. You can set the size and initial
-     * contents of the buffer using the `len' and `b' arguments. You can open
-     * a file and attach it to the stream by specifying the file descriptor,
-     * `f'.
-     */
-    ofpstream( int f, char *b, int len );
-    /**
-     * Destroys the ofpstream object.
-     */
+    ofpstream(const char name[], std::ios::openmode omode = std::ios::out);
     ~ofpstream();
-    /**
-     * Returns the current file buffer.
-     */
-    filebuf * rdbuf();
-    /**
-     * Opens the the named file in the given mode (app, ate, in, out, binary,
-     * trunc, nocreate, or noreplace) and protection. The default mode is out
-     * (output) with openprot protection. The opened file is attached to this
-     * stream.
-     */
-    void open( const char *name, int omode = ios::out,
-        int prot = filebuf::openprot );
+    void open(const char name[], std::ios::openmode omode = std::ios::out);
 };
 
 #endif  // Uses_ofpstream
 
 /* ------------------------------------------------------------------------*/
-/*                                                                         */
 /*   class fpstream                                                        */
-/*                                                                         */
-/*   Base class for reading and writing streamable objects to              */
-/*   bidirectional file streams                                            */
-/*                                                                         */
 /* ------------------------------------------------------------------------*/
 
 #if defined( Uses_fpstream ) && !defined( __fpstream )
 #define __fpstream
 
-#include <iostream.h>
-
 /**
- * fpstream is a simple "mix" of its bases, @ref fpbase and @ref iopstream.
- * It provides the base class for simultaneous writing and reading streamable
- * objects to bidirectional file streams. It is analogous to class fstream,
- * defined in `fstream.h' for the standard C++ stream library.
- * @short Provides the base class for simultaneous writing and reading
- * streamable objects to bidirectional file streams
+ * fpstream provides the base class for simultaneous writing and
+ * reading streamable objects to bidirectional file streams.
+ *
+ * @short The base class for simultaneous writing and reading
+ * streamable objects to bidirectional file streams.
  */
-class fpstream : public fpbase, public iopstream
-{
+class fpstream : public iopstream {
+    std::filebuf	buf;
 public:
-    /**
-     * Creates a buffered fpstream object.
-     */
     fpstream();
-    /**
-     * Creates a buffered fpstream object. You can open a file and attach it
-     * to the stream by specifying the `name', `omode', and `prot'
-     * (protection) arguments.
-     */
-    fpstream( const char *name, int omode, int prot = filebuf::openprot );
-    /**
-     * Creates a buffered fpstream object. You can open a file and attach it
-     * to the stream by specifying the file descriptor, `f'.
-     */
-    fpstream( int f );
-    /**
-     * Creates a buffered fpstream object. You can set the size and initial
-     * contents of the buffer using the `len' and `b' arguments. You can open
-     * a file and attach it to the stream by specifying the file descriptor,
-     * `f'.
-     */
-    fpstream( int f, char *b, int len );
-    /**
-     * Destroys the fpstream object.
-     */
+    fpstream(const char name[], std::ios::openmode omode);
     ~fpstream();
-    /**
-     * Returns the data member bp.
-     */
-    filebuf * rdbuf();
-    /**
-     * Opens the named file in the given mode (app, ate, in, out, binary,
-     * trunc, nocreate, noreplace) and protection. The opened file is
-     * attatched to this stream.
-     */
-    void open( const char *name, int omode, int prot = filebuf::openprot );
+    void open(const char name[], std::ios::openmode omode);
 };
 
 #endif  // Uses_fpstream

--- lib/tobjstrm.cc.orig	Thu Jul 26 09:59:21 2001
+++ lib/tobjstrm.cc	Mon Jan 13 21:26:49 2003
@@ -1,5 +1,5 @@
-/*
- * tobjstrm.cc
+/**
+ * @file tobjstrm.cc
  *
  * Turbo Vision - Version 2.0
  *
@@ -7,6 +7,7 @@
  * All Rights Reserved.
  *
  * Modified by Sergio Sigala <sergio@sigala.it>
+ * Modified by Max Okumoto <okumoto@ucsd.edu>
  */
 
 #define Uses_TStreamable
@@ -18,23 +19,29 @@
 #define Uses_ipstream
 #define Uses_opstream
 #define Uses_iopstream
-#define Uses_fpbase
 #define Uses_ifpstream
 #define Uses_ofpstream
 #define Uses_fpstream
 #include <tvision/tv.h>
 
+#include <fstream>
+#include <ios>
+
 #include <assert.h>
 #include <fcntl.h>
-#include <fstream.h>
 #include <limits.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
+#include <arpa/inet.h>
+
+extern "C" {
+    #include <sys/param.h>
+}
 
 const uchar nullStringLen = UCHAR_MAX;
 
-TStreamableClass::TStreamableClass( const char *n, BUILDER b, int d ) :
+TStreamableClass::TStreamableClass(const char *n, BUILDER b, int d ) :
     name( n ),
     build( b ),
     delta( d )
@@ -47,21 +54,17 @@
 {
 }
 
-void *TStreamableTypes::operator new( size_t, void * arena )
-{
-    return arena;
-}
-
 TStreamableTypes::~TStreamableTypes()
 {
 }
 
-void TStreamableTypes::registerType( const TStreamableClass *d )
+void
+TStreamableTypes::registerType(const TStreamableClass *d )
 {
     insert( (void *)d );
 }
 
-const TStreamableClass *TStreamableTypes::lookup( const char *name )
+const TStreamableClass *TStreamableTypes::lookup(const char name[] )
 {
     ccIndex loc;
     if( search( (void *)name, loc ) )
@@ -70,7 +73,8 @@
         return 0;
 }
 
-void *TStreamableTypes::keyOf( void *d )
+void *
+TStreamableTypes::keyOf( void *d )
 {
     return (void *)((TStreamableClass *)d)->name;
 }
@@ -88,13 +92,14 @@
 {
 }
 
-void TPWrittenObjects::registerObject( const void *adr )
+void
+TPWrittenObjects::registerObject(const void *adr )
 {
     TPWObj *o = new TPWObj( adr, curId++ );
     insert( o );
 }
 
-P_id_type TPWrittenObjects::find( const void *d )
+P_id_type TPWrittenObjects::find(const void *d )
 {
     ccIndex loc;
     if( search( (void *)d, loc ) )
@@ -103,7 +108,8 @@
         return P_id_notFound;
 }
 
-void *TPWrittenObjects::keyOf( void *d )
+void *
+TPWrittenObjects::keyOf( void *d )
 {
     return (void *)((TPWObj *)d)->address;
 }
@@ -118,7 +124,7 @@
         return 1;
 }
 
-TPWObj::TPWObj( const void *adr, P_id_type id ) : address( adr ), ident( id )
+TPWObj::TPWObj(const void *adr, P_id_type id ) : address( adr ), ident( id )
 {
 }
 
@@ -130,7 +136,8 @@
 {
 }
 
-void TPReadObjects::registerObject( const void *adr )
+void
+TPReadObjects::registerObject(const void *adr )
 {
     ccIndex loc = insert( (void *)adr );
 #ifndef __UNPATCHED
@@ -150,398 +157,518 @@
     return at( id );
 }
 
-pstream::pstream( streambuf *sb )
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
+
+/**
+ * This form allocates a default buffer.
+ */
+pstream::pstream()
 {
-    init( sb );
 }
 
+/**
+ * Destroys the pstream object.
+ */
 pstream::~pstream()
 {
 }
 
-void pstream::initTypes()
+/**
+ * Creates the associated @ref TStreamableTypes object types. Called by the
+ * @ref TStreamableClass constructor.
+ */
+void
+pstream::initTypes()
 {
-    if( types == 0 )
+    if (types == 0)
         types = new TStreamableTypes;
 }
 
-int pstream::rdstate() const
-{
-    return state;
-}
-
-int pstream::eof() const
-{
-    return state & ios::eofbit;
-}
-
-int pstream::fail() const
-{
-    return state & (ios::failbit | ios::badbit); //| ios::hardfail);
-}
-
-int pstream::bad() const
-{
-    return state & (ios::badbit); //| ios::hardfail);
-}
-
-int pstream::good() const
-{
-    return state == 0;
-}
-
-void pstream::clear( int i )
-{
-    state = (i & 0xFF); //| (state & ios::hardfail);
-}
-
-void pstream::registerType( TStreamableClass *ts )
-{
-    types->registerType( ts );
-}
-
-pstream::operator void *() const
-{
-    return fail() ? 0 : (void *)this;
-}
-
-int pstream::operator! () const
-{
-    return fail();
-}
-
-streambuf * pstream::rdbuf() const
-{
-    return bp;
-}
-
-pstream::pstream()
+/**
+ * Undocumented.
+ */
+void
+pstream::registerType(TStreamableClass *ts)
 {
+    types->registerType(ts);
 }
 
-void pstream::error( StreamableError )
+/**
+ * Sets the given error condition, where StreamableError is defined as
+ * follows:
+ *
+ * <pre>
+ * enum StreamableError { peNotRegistered, peInvalidType };
+ * </pre>
+ */
+void
+pstream::error(StreamableError)
 {
     abort();
 }
 
-void pstream::error( StreamableError, const TStreamable& )
+/**
+ * Sets the given error condition, where StreamableError is defined as
+ * follows:
+ *
+ * <pre>
+ * enum StreamableError { peNotRegistered, peInvalidType };
+ * </pre>
+ */
+void
+pstream::error(StreamableError, const TStreamable&)
 {
     abort();
 }
 
-void pstream::init( streambuf *sbp )
-{
-    state = 0;
-    bp = sbp;
-}
-
-void pstream::setstate( int b )
-{
-    state |= (b&0xFF);
-}
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
 
-ipstream::ipstream( streambuf *sb )
+/**
+ * This form creates a buffered ipstream with the given buffer.
+ */
+ipstream::ipstream(std::streambuf *sb)
+    : std::istream(sb)
 {
-    pstream::init( sb );
 }
 
+/**
+ * Destroys the ipstream object.
+ */
 ipstream::~ipstream()
 {
     objs.shouldDelete = False;
     objs.shutDown();
 }
 
-streampos ipstream::tellg()
-{
-    return bp->seekoff( 0, ios::cur, ios::in );
-}
-
-ipstream& ipstream::seekg( streampos pos )
+/**
+ * This form moves the stream's current position to the absolute
+ * position given by `pos'.
+ */
+ipstream &
+ipstream::seekg(std::streampos pos)
 {
     objs.removeAll();
-    bp->seekoff( pos, ios::beg );
+    std::istream::seekg(pos);
     return *this;
 }
 
-ipstream& ipstream::seekg( streamoff off, ios::seek_dir dir )
+/**
+ * This form moves to a position relative to the current position by an
+ * offset `off' (+ or -) starting at `dir'. Parameter `dir' can be set to:
+ *
+ * <pre>
+ * beg (start of stream)
+ *
+ * cur (current stream position)
+ *
+ * end (end of stream)
+ * </pre>
+ */
+ipstream &
+ipstream::seekg(std::streamoff off, std::ios::seekdir dir)
 {
     objs.removeAll();
-    bp->seekoff( off, dir );
+    std::istream::seekg(off, dir);
     return *this;
 }
 
-uchar ipstream::readByte()
+/**
+ * Returns the word at the current stream position.
+ */
+uchar
+ipstream::readByte()
 {
-    return bp->sbumpc();
+    uchar val;
+
+    read((char *)&val, 1);
+    return val;
 }
 
-ushort ipstream::readWord()
+/**
+ * Returns the word at the current stream position.
+ */
+ushort
+ipstream::readWord()
 {
     /* SS: words are stored in little endian format (LSB first) */
-    return readByte() | (readByte() << 8);
+    ushort val;
+
+    read((char *)&val, 2);
+    val = ntohs(val);
+    return val;
 }
 
-void ipstream::readBytes( void *data, size_t sz )
+/**
+ * Returns the long at the current stream position.
+ */
+ulong
+ipstream::readLong()
 {
-    bp->sgetn( (char *)data, sz );
+    /* SS: ints are stored in little endian format (LSB first) */
+    ulong val;
+
+    read((char *)&val, 4);
+    val = ntohl(val);
+    return val;
 }
 
-char *ipstream::readString()
+/**
+ * Reads `sz' bytes from current stream position, and writes them to
+ * the address given in `data'.
+ */
+void
+ipstream::readBytes(void *data, std::streamsize sz)
 {
-    uchar len = readByte();
-    if( len == nullStringLen )
-        return 0;
+    read((char *)data, sz);
+}
+
+/**
+ * Returns a string read from the current stream position.
+ */
+char *
+ipstream::readString()
+{
+    int ch = get();
+    if (ch == EOF) {
+	return NULL;
+    }
+
+    uchar len = ch;
+    if (len == nullStringLen) {
+	return NULL;
+    }
+
     char *buf = new char[len+1];
-    if( buf == 0 )
-        return 0;
-    readBytes( buf, len );
+
+    read(buf, len);
     buf[len] = EOS;
+
     return buf;
 }
 
-char *ipstream::readString( char *buf, unsigned maxLen )
+/**
+ * Returns a string read from the current stream position.
+ */
+char *
+ipstream::readString(char *buf, unsigned maxLen)
 {
-    assert( buf != 0 );
+    assert(buf != NULL);
 
-    uchar len = readByte();
-    if( len > maxLen-1 )
-        return 0;
-    readBytes( buf, len );
+    int len = get();
+    if (len == EOF) {
+	return NULL;
+    }
+
+    assert(len < maxLen);
+
+    read(buf, len);
     buf[len] = EOS;
+
     return buf;
 }
 
-ipstream& operator >> ( ipstream& ps, char &ch )
+ipstream &
+ipstream::operator>>(char &ch)
 {
-    ch = ps.readByte();
-    return ps;
+    int c = get();
+    if (c != EOF) {
+	ch = (char)c;
+    }
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, signed char &ch )
-{
-    ch = ps.readByte();
-    return ps;
-}
 
-ipstream& operator >> ( ipstream& ps, unsigned char &ch )
+ipstream &
+ipstream::operator>>(signed char &ch)
 {
-    ch = ps.readByte();
-    return ps;
+    int c = get();
+    if (c != EOF) {
+	ch = (signed char)c;
+    }
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, signed short &sh )
+ipstream &
+ipstream::operator>>(unsigned char &ch)
 {
-    sh = ps.readWord();
-    return ps;
+    int c = get();
+    if (c != EOF) {
+	ch = (unsigned char)c;
+    }
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, unsigned short &sh )
+ipstream &
+ipstream::operator>>(signed short &sh)
 {
-    sh = ps.readWord();
-    return ps;
+    sh = readWord();
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, signed int &i )
+ipstream &
+ipstream::operator>>(unsigned short &sh)
 {
-    /* SS: ints are stored in little endian format (LSB first) */
-    i = ps.readByte() | (ps.readByte() << 8) | (ps.readByte() << 16) |
-	(ps.readByte() << 24);
-    return ps;
+    sh = readWord();
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, unsigned int &i )
+ipstream &
+ipstream::operator>>(signed int &i)
 {
-    /* SS: ints are stored in little endian format (LSB first) */
-    i = ps.readByte() | (ps.readByte() << 8) | (ps.readByte() << 16) |
-	(ps.readByte() << 24);
-    return ps;
+    i = readLong();
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, signed long &l )
+ipstream &
+ipstream::operator>>(unsigned int &i)
 {
-    /* SS: longs are stored in little endian format (LSB first) */
-    l = ps.readByte() | (ps.readByte() << 8) | (ps.readByte() << 16) |
-	(ps.readByte() << 24);
-    return ps;
+    i = readLong();
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, unsigned long &l )
+ipstream &
+ipstream::operator>>(signed long &l)
 {
-    /* SS: longs are stored in little endian format (LSB first) */
-    l = ps.readByte() | (ps.readByte() << 8) | (ps.readByte() << 16) |
-	(ps.readByte() << 24);
-    return ps;
+    l = readLong();
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, float &f )
+ipstream &
+ipstream::operator>>(unsigned long &l)
 {
-    ps.readBytes( &f, sizeof(f) );
-    return ps;
+    l = readLong();
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, double &d )
+ipstream &
+ipstream::operator>>(float &f)
 {
-    ps.readBytes( &d, sizeof(d) );
-    return ps;
+    read((char *)&f, sizeof(f));
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, long double &ld )
+ipstream &
+ipstream::operator>>(double &d)
 {
-    ps.readBytes( &ld, sizeof(ld) );
-    return ps;
+    read((char *)&d, sizeof(d));
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, TStreamable& t )
+ipstream &
+ipstream::operator>>(long double &ld)
 {
-    const TStreamableClass *pc = ps.readPrefix();
-    ps.readData( pc, &t );
-    ps.readSuffix();
-    return ps;
+    read((char *)&ld, sizeof(ld));
+    return *this;
 }
 
-ipstream& operator >> ( ipstream& ps, void *&t )
+ipstream &
+ipstream::operator>>(TStreamable& t)
 {
-    char ch = ps.readByte();
-    switch( ch )
-        {
-        case pstream::ptNull:
-            t = 0;
-            break;
-        case pstream::ptIndexed:
-            {
-            P_id_type index = ps.readWord();
-            t = (void *)ps.find( index );
-            assert( t != 0 );
-            break;
-            }
-        case pstream::ptObject:
-            {
-            const TStreamableClass *pc = ps.readPrefix();
-            t = ps.readData( pc, 0 );
-            ps.readSuffix();
-            break;
-            }
-        default:
-            ps.error( pstream::peInvalidType );
-            break;
-        }
-    return ps;
+    const TStreamableClass *pc = readPrefix();
+    readData(pc, &t);
+    readSuffix();
+    return *this;
 }
 
-ipstream::ipstream()
+ipstream &
+ipstream::operator>>(void *&t)
 {
+    int ch = get();
+    switch (ch) {
+    case pstream::ptNull:
+	{
+	t = 0;
+	break;
+	}
+    case pstream::ptIndexed:
+	{
+	P_id_type index = readWord();
+	t = (void *)find(index);
+	assert(t != 0);
+	break;
+	}
+    case pstream::ptObject:
+	{
+	const TStreamableClass *pc = readPrefix();
+	t = readData(pc, 0);
+	readSuffix();
+	break;
+	}
+    default:
+	error(pstream::peInvalidType);
+	break;
+    }
+    return *this;
 }
 
-const TStreamableClass *ipstream::readPrefix()
+/**
+ * Returns the @ref TStreamableClass object corresponding to the class
+ * name stored at the current position.
+ */
+const TStreamableClass *
+ipstream::readPrefix()
 {
-    char ch = readByte();
-    assert( ch == '[' );    // don't combine this with the previous line!
+    int ch = get();
+    assert(ch == '[');    // don't combine this with the previous line!
                             // We must always do the read, even if we're
                             // not checking assertions
 
     char name[128];
-    readString( name, sizeof name );
-    return types->lookup( name );
+    readString(name, sizeof name);
+    return types->lookup(name);
 }
 
-void *ipstream::readData( const TStreamableClass *c, TStreamable *mem )
+/**
+ * Invokes the appropriate read function to read from the stream to the
+ * object `mem'. If `mem' is 0, the appropriate build function is called
+ * first.
+ */
+void *
+ipstream::readData(const TStreamableClass *c, TStreamable *mem)
 {
-    if( mem == 0 )
+    if (mem == 0)
         mem = c->build();
 
-    registerObject( (char *)mem - c->delta );   // register the actual address
-                                        // of the object, not the address
-                                        // of the TStreamable sub-object
-    return mem->read( *this );
+    /*
+     * Register the actual address of the object, not the address
+     * of the TStreamable sub-object
+     */
+    registerObject((char *)mem - c->delta);
+    return mem->read(*this);
 }
 
-void ipstream::readSuffix()
+/**
+ * Reads and checks the final byte of an object's name field.
+ */
+void
+ipstream::readSuffix()
 {
-    char ch = readByte();
-    assert( ch == ']' );    // don't combine this with the previous line!
-                            // We must always do the write, even if we're
-                            // not checking assertions
+    int ch = get();
 
+    /*
+     * Don't combine this with the previous line!
+     * We must always do the write, even if we're
+     * not checking assertions
+     */
+    assert(ch == ']');
 }
 
-const void *ipstream::find( P_id_type id )
+/**
+ * Returns a pointer to the object corresponding to `id'.
+ */
+const void *
+ipstream::find(P_id_type id)
 {
-    return objs.find( id );
+    return objs.find(id);
 }
 
-void ipstream::registerObject( const void *adr )
+/**
+ * Registers the class of the object pointed by `adr'.
+ */
+void
+ipstream::registerObject(const void *adr)
 {
-    objs.registerObject( adr );
+    objs.registerObject(adr);
 }
 
-opstream::opstream()
-{
-    objs = new TPWrittenObjects;
-}
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
 
-opstream::opstream( streambuf * sb )
+/**
+ * This form creates a buffered opstream with the given buffer.
+ */
+opstream::opstream(std::streambuf *sb)
+    : std::ostream(sb)
 {
-    objs = new TPWrittenObjects;
-    pstream::init( sb );
 }
 
+/**
+ * Destroys the opstream object.
+ */
 opstream::~opstream()
 {
-    objs->shutDown();
-    delete objs;
+    objs.shutDown();
 }
 
-opstream& opstream::seekp( streampos pos )
+/**
+ * This form moves the stream's current position to the absolute
+ * position given by `pos'.
+ */
+opstream &
+opstream::seekp(std::streampos pos)
 {
 #ifndef __UNPATCHED
-    objs->freeAll();   // CMF 07.11.92 --- delete the TPWObj's
+    objs.freeAll();   // CMF 07.11.92 --- delete the TPWObj's
 #endif
-    objs->removeAll();
-    bp->seekoff( pos, ios::beg );
+    objs.removeAll();
+    std::ostream::seekp(pos);
     return *this;
 }
 
-opstream& opstream::seekp( streamoff pos, ios::seek_dir dir )
+/**
+ * This form moves to a position relative to the current position by an
+ * offset `off' (+ or -) starting at `dir'. Parameter `dir' can be set to:
+ *
+ * <pre>
+ * beg (start of stream)
+ *
+ * cur (current stream position)
+ *
+ * end (end of stream)
+ * </pre>
+ */
+opstream &
+opstream::seekp(std::streamoff off, std::ios::seekdir dir)
 {
 #ifndef __UNPATCHED
-    objs->freeAll();   // CMF 07.11.92 ... s.a.
+    objs.freeAll();   // CMF 07.11.92 ... s.a.
 #endif
-    objs->removeAll();
-    bp->seekoff( pos, dir );
-    return *this;
-}
-
-streampos opstream::tellp()
-{
-    return bp->seekoff( 0, ios::cur, ios::out );
-}
-
-opstream& opstream::flush()
-{
-    bp->sync();
+    objs.removeAll();
+    std::ostream::seekp(off, dir);
     return *this;
 }
 
-void opstream::writeByte( uchar ch )
+/**
+ * Writes character `ch' to the stream.
+ */
+void
+opstream::writeByte(uchar ch)
 {
-    bp->sputc( ch );
+    write((char *)&ch, 1);
 }
 
-void opstream::writeBytes( const void *data, size_t sz )
+/**
+ * Writes `sz' bytes from `data' buffer to the stream.
+ */
+void
+opstream::writeBytes(const void *data, std::streamsize sz)
 {
-    bp->sputn( (char *)data, sz );
+    write((char *)data, sz);
 }
 
-void opstream::writeWord( ushort sh )
+/**
+ * Writes the word `us' to the stream.
+ */
+void
+opstream::writeWord( ushort sh )
 {
     /* SS: words are stored in little endian format (LSB first) */
     writeByte(sh & 0xff);
     writeByte((sh >> 8) & 0xff);
 }
 
-void opstream::writeString( const char *str )
+/**
+ * Writes `str' to the stream (together with a leading length byte).
+ */
+void
+opstream::writeString(const char *str )
 {
-    if( str == 0 )
+    if (str == 0 )
         {
         writeByte( nullStringLen );
         return;
@@ -551,128 +678,155 @@
     writeBytes( str, len );
 }
 
-opstream& operator << ( opstream& ps, char ch )
+opstream &
+opstream::operator<<(char ch)
 {
-    ps.writeByte( ch );
-    return ps;
+    writeByte( ch );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, signed char ch )
+opstream &
+opstream::operator<<(signed char ch)
 {
-    ps.writeByte( ch );
-    return ps;
+    writeByte( ch );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, unsigned char ch )
+opstream &
+opstream::operator<<(unsigned char ch)
 {
-    ps.writeByte( ch );
-    return ps;
+    writeByte( ch );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, signed short sh )
+opstream &
+opstream::operator<<(signed short sh)
 {
-    ps.writeWord( sh );
-    return ps;
+    writeWord( sh );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, unsigned short sh )
+opstream &
+opstream::operator<<(unsigned short sh)
 {
-    ps.writeWord( sh );
-    return ps;
+    writeWord( sh );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, signed int i )
+opstream &
+opstream::operator<<(signed int i)
 {
     /* SS: ints are stored in little endian format (LSB first) */
-    ps.writeByte(i & 0xff);
-    ps.writeByte((i >> 8) & 0xff);
-    ps.writeByte((i >> 16) & 0xff);
-    ps.writeByte((i >> 24) & 0xff);
-    return ps;
+    writeByte(i & 0xff);
+    writeByte((i >> 8) & 0xff);
+    writeByte((i >> 16) & 0xff);
+    writeByte((i >> 24) & 0xff);
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, unsigned int i )
+opstream &
+opstream::operator<<(unsigned int i)
 {
     /* SS: ints are stored in little endian format (LSB first) */
-    ps.writeByte(i & 0xff);
-    ps.writeByte((i >> 8) & 0xff);
-    ps.writeByte((i >> 16) & 0xff);
-    ps.writeByte((i >> 24) & 0xff);
-    return ps;
+    writeByte(i & 0xff);
+    writeByte((i >> 8) & 0xff);
+    writeByte((i >> 16) & 0xff);
+    writeByte((i >> 24) & 0xff);
+    return *this;
 }
-opstream& operator << ( opstream& ps, signed long l )
+opstream &
+opstream::operator<<(signed long l)
 {
     /* SS: longs are stored in little endian format (LSB first) */
-    ps.writeByte(l & 0xff);
-    ps.writeByte((l >> 8) & 0xff);
-    ps.writeByte((l >> 16) & 0xff);
-    ps.writeByte((l >> 24) & 0xff);
-    return ps;
+    writeByte(l & 0xff);
+    writeByte((l >> 8) & 0xff);
+    writeByte((l >> 16) & 0xff);
+    writeByte((l >> 24) & 0xff);
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, unsigned long l )
+opstream &
+opstream::operator<<(unsigned long l)
 {
     /* SS: longs are stored in little endian format (LSB first) */
-    ps.writeByte(l & 0xff);
-    ps.writeByte((l >> 8) & 0xff);
-    ps.writeByte((l >> 16) & 0xff);
-    ps.writeByte((l >> 24) & 0xff);
-    return ps;
+    writeByte(l & 0xff);
+    writeByte((l >> 8) & 0xff);
+    writeByte((l >> 16) & 0xff);
+    writeByte((l >> 24) & 0xff);
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, float f )
+opstream &
+opstream::operator<<(float f )
 {
-    ps.writeBytes( &f, sizeof(f) );
-    return ps;
+    writeBytes( &f, sizeof(f) );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, double d )
+opstream &
+opstream::operator<<(double d )
 {
-    ps.writeBytes( &d, sizeof(d) );
-    return ps;
+    writeBytes( &d, sizeof(d) );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, long double ld )
+opstream &
+opstream::operator<<(long double ld )
 {
-    ps.writeBytes( &ld, sizeof(ld) );
-    return ps;
+    writeBytes( &ld, sizeof(ld) );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, TStreamable& t )
+opstream &
+opstream::operator<<(TStreamable &t)
 {
-    ps.writePrefix( t );
-    ps.writeData( t );
-    ps.writeSuffix( t );
-    return ps;
+    writePrefix( t );
+    writeData( t );
+    writeSuffix( t );
+    return *this;
 }
 
-opstream& operator << ( opstream& ps, TStreamable *t )
+opstream &
+opstream::operator<<(TStreamable *t)
 {
     P_id_type index;
-    if( t == 0 )
-        ps.writeByte( pstream::ptNull );
-    else if( (index = ps.find( t )) != P_id_notFound )
+    if (t == 0 )
+        writeByte( pstream::ptNull );
+    else if ((index = find( t )) != P_id_notFound )
         {
-        ps.writeByte( pstream::ptIndexed );
-        ps.writeWord( index );
+        writeByte( pstream::ptIndexed );
+        writeWord( index );
         }
     else
         {
-        ps.writeByte( pstream::ptObject );
-        ps << *t;
+        writeByte( pstream::ptObject );
+        *this << *t;
         }
-    return ps;
+    return *this;
 }
 
-void opstream::writePrefix( const TStreamable& t )
+/**
+ * Writes the class name prefix to the stream.
+ *
+ * The << operator uses this function to write a prefix and suffix around
+ * the data written with @ref writeData(). The prefix/suffix is used to
+ * ensure type-safe stream I/O.
+ */
+void
+opstream::writePrefix(const TStreamable& t )
 {
     writeByte( '[' );
     writeString( t.streamableName() );
 }
 
-void opstream::writeData( TStreamable& t )
+/**
+ * Writes data to the stream by calling the appropriate class's write
+ * member function for the object being written.
+ */
+void
+opstream::writeData( TStreamable& t )
 {
-    if( types->lookup( t.streamableName() ) == 0 )
+    if (types->lookup( t.streamableName() ) == 0 )
         error( peNotRegistered, t );
     else
         {
@@ -681,189 +835,191 @@
         }
 }
 
-void opstream::writeSuffix( const TStreamable& )
-{
-    writeByte( ']' );
-}
-
-P_id_type opstream::find( const void *adr )
-{
-    return objs->find( adr );
-}
-
-void opstream::registerObject( const void *adr )
-{
-    objs->registerObject( adr );
-}
-
-iopstream::iopstream( streambuf * sb )
-{
-    pstream::init( sb );
-}
-
-iopstream::~iopstream()
-{
-}
-
-iopstream::iopstream()
-{
-}
-
-fpbase::fpbase()
-{
-    pstream::init( &buf );
-}
-
-fpbase::fpbase( const char *name, int omode, int prot )
-{
-    pstream::init( &buf );
-    open( name, omode, prot );
-}
-
-fpbase::fpbase( int f ) : buf( f )
-{
-    pstream::init( &buf );
-}
-
-fpbase::fpbase( int f, char *b, int len ) : buf( f, b, len )
+/**
+ * Writes the class name suffix to the stream.
+ *
+ * The << operator uses this function to write a prefix and suffix around
+ * the data written with @ref writeData(). The prefix/suffix is used to
+ * ensure type-safe stream I/O.
+ */
+void
+opstream::writeSuffix(const TStreamable &)
 {
-    pstream::init( &buf );
+    writeByte(']');
 }
 
-fpbase::~fpbase()
+/**
+ * Returns the type ID for the object ad address `adr'.
+ */
+P_id_type
+opstream::find(const void *adr)
 {
+    return objs.find(adr);
 }
 
-void fpbase::open( const char *b, int m, int prot )
+/**
+ * Registers the class of the object pointed by `adr'.
+ */
+void
+opstream::registerObject(const void *adr)
 {
-    if( buf.is_open() )
-        clear(ios::failbit);        // fail - already open
-    else if( buf.open(b, m, prot) )
-        clear(ios::goodbit);        // successful open
-    else
-        clear(ios::badbit);     // open failed
+    objs.registerObject(adr);
 }
 
-void fpbase::attach( int f )
-{
-    if( buf.is_open() )
-        setstate(ios::failbit);
-    else if( buf.attach(f) )
-        clear(ios::goodbit);
-    else
-        clear(ios::badbit);
-}
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
 
-void fpbase::close()
+/**
+ * This form creates a buffered iopstream with the given buffer.
+ */
+iopstream::iopstream(std::streambuf *sb)
+    : ipstream(sb), opstream(sb)
 {
-    if( buf.close() )
-        clear(ios::goodbit);
-    else
-        setstate(ios::failbit);
 }
 
-void fpbase::setbuf(char* b, int len)
+/**
+ * Destroys the iopstream object.
+ */
+iopstream::~iopstream()
 {
-    if( buf.setbuf(b, len) )
-        clear(ios::goodbit);
-    else
-        setstate(ios::failbit);
 }
 
-filebuf *fpbase::rdbuf()
-{
-    return &buf;
-}
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
 
+/**
+ * Creates a buffered ifpstream object.
+ */
 ifpstream::ifpstream()
+    : ipstream(NULL), buf()
 {
+    init(&buf);
 }
 
-ifpstream::ifpstream( const char* name, int omode, int prot ) :
-        fpbase( name, omode | ios::in | ios::bin, prot )
-{
-}
-
-ifpstream::ifpstream( int f ) : fpbase( f )
-{
-}
-
-ifpstream::ifpstream(int f, char* b, int len) : fpbase(f, b, len)
+/**
+ * Creates a buffered ifpstream object. You can open a file and attach it
+ * to the stream by specifying the `name' and `omode' arguments.
+ */
+ifpstream::ifpstream(const char name[], std::ios::openmode omode)
+    : ipstream(NULL), buf()
 {
+    init(&buf);
+    open(name, omode);
 }
 
+/**
+ * Destroys the ifpstream object.
+ */
 ifpstream::~ifpstream()
 {
 }
 
-filebuf *ifpstream::rdbuf()
-{
-    return fpbase::rdbuf();
-}
-
-void ifpstream::open( const char *name, int omode, int prot )
+/**
+ * Opens the the named file in the given mode (app, ate, in, out, binary,
+ * trunc, nocreate, or noreplace) and protection.  The opened file is
+ * attached to this stream.
+ */
+void
+ifpstream::open(const char name[], std::ios::openmode omode)
 {
-    fpbase::open( name, omode | ios::in | ios::bin, prot );
-}
+    using std::ios;
 
-ofpstream::ofpstream()
-{
+    if (!buf.open(name, omode | ios::in | ios::binary)) {
+	this->setstate(ios_base::failbit);
+    }
 }
 
-ofpstream::ofpstream( const char* name, int omode, int prot ) :
-        fpbase( name, omode | ios::out | ios::bin, prot )
-{
-}
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
 
-ofpstream::ofpstream( int f ) : fpbase( f )
+/**
+ * Creates a buffered ofpstream object.
+ */
+ofpstream::ofpstream()
+    : opstream(NULL), buf()
 {
+    init(&buf);
 }
 
-ofpstream::ofpstream(int f, char* b, int len) : fpbase(f, b, len)
+/**
+ * Creates a buffered ofpstream object. You can open a file and attach it
+ * to the stream by specifying the `name' and `omode' arguments.
+ */
+ofpstream::ofpstream(const char name[], std::ios::openmode omode)
+    : opstream(NULL), buf()
 {
+    init(&buf);
+    open(name, omode);
 }
 
+/**
+ * Destroys the ofpstream object.
+ */
 ofpstream::~ofpstream()
 {
 }
 
-filebuf *ofpstream::rdbuf()
-{
-    return fpbase::rdbuf();
-}
-
-void ofpstream::open( const char *name, int omode, int prot )
+/**
+ * Opens the the named file in the given mode (app, ate, in, out, binary,
+ * trunc, nocreate, or noreplace) and protection.  The opened file is
+ * attached to this stream. 
+ */
+void
+ofpstream::open(const char name[], std::ios::openmode omode)
 {
-    fpbase::open( name, omode | ios::out | ios::bin, prot );
-}
+    using std::ios;
 
-fpstream::fpstream()
-{
+    if (!buf.open(name, omode | ios::out | ios::binary)) {
+	this->setstate(ios_base::failbit);
+    }
 }
 
-fpstream::fpstream( const char* name, int omode, int prot ) :
-        fpbase( name, omode | ios::out | ios::bin, prot )
-{
-}
+/*---------------------------------------------------------------------------*
+ *
+ *---------------------------------------------------------------------------*/
 
-fpstream::fpstream( int f ) : fpbase( f )
+/**
+ * Creates a buffered fpstream object.
+ */
+fpstream::fpstream()
+    : iopstream(NULL), buf()
 {
+    init(&buf);
 }
 
-fpstream::fpstream(int f, char* b, int len) : fpbase(f, b, len)
+/**
+ * Creates a buffered fpstream object. You can open a file and attach it
+ * to the stream by specifying the `name' and `omode' arguments.
+ */
+fpstream::fpstream(const char name[], std::ios::openmode omode)
+    : iopstream(NULL), buf()
 {
+    init(&buf);
+    open(name, omode);
 }
 
+/**
+ * Destroys the fpstream object.
+ */
 fpstream::~fpstream()
 {
 }
 
-filebuf *fpstream::rdbuf()
+/**
+ * Opens the named file in the given mode (app, ate, in, out, binary,
+ * trunc, nocreate, noreplace) and protection. The opened file is
+ * attatched to this stream.
+ */
+void
+fpstream::open(const char name[], std::ios::openmode omode)
 {
-    return fpbase::rdbuf();
-}
+    using std::ios;
 
-void fpstream::open( const char *name, int omode, int prot )
-{
-    fpbase::open( name, omode | ios::in | ios::out | ios::bin, prot );
+    if (!buf.open(name, omode | ios::in | ios::out | ios::binary)) {
+	this->setstate(ios_base::failbit);
+    }
 }
+

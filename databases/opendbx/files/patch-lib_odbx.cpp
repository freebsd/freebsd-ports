--- lib/odbx.cpp.orig	2010-08-01 02:08:41 UTC
+++ lib/odbx.cpp
@@ -54,7 +54,7 @@ namespace OpenDBX
 	*  OpenDBX large object interface
 	*/
 
-	Lob::Lob( Lob_Iface* impl ) throw( std::exception )
+	Lob::Lob( Lob_Iface* impl ) noexcept(false)
 	{
 		m_impl = impl;
 		m_ref = new int;
@@ -114,21 +114,21 @@ namespace OpenDBX
 
 
 
-	void Lob::close() throw( std::exception )
+	void Lob::close() noexcept(false)
 	{
 		return m_impl->close();
 	}
 
 
 
-	ssize_t Lob::read( void* buffer, size_t buflen ) throw( std::exception )
+	ssize_t Lob::read( void* buffer, size_t buflen ) noexcept(false)
 	{
 		return m_impl->read( buffer, buflen );
 	}
 
 
 
-	ssize_t Lob::write( void* buffer, size_t buflen ) throw( std::exception )
+	ssize_t Lob::write( void* buffer, size_t buflen ) noexcept(false)
 	{
 		return m_impl->write( buffer, buflen );
 	}
@@ -143,7 +143,7 @@ namespace OpenDBX
 
 
 
-	Result::Result( Result_Iface* impl ) throw( std::exception )
+	Result::Result( Result_Iface* impl ) noexcept(false)
 	{
 		m_impl = impl;
 		m_ref = new int;
@@ -204,76 +204,76 @@ namespace OpenDBX
 
 
 
-	void Result::finish() throw( std::exception )
+	void Result::finish() noexcept(false)
 	{
 		return m_impl->finish();
 	}
 
 
 
-	odbxres Result::getResult( struct timeval* timeout, unsigned long chunk ) throw( std::exception )
+	odbxres Result::getResult( struct timeval* timeout, unsigned long chunk ) noexcept(false)
 	{
 		return m_impl->getResult( timeout, chunk );
 	}
 
 
 
-	odbxrow Result::getRow() throw( std::exception )
+	odbxrow Result::getRow() noexcept(false)
 	{
 		return m_impl->getRow();
 	}
 
 
 
-	uint64_t Result::rowsAffected() throw( std::exception )
+	uint64_t Result::rowsAffected() noexcept(false)
 	{
 		return m_impl->rowsAffected();
 	}
 
 
 
-	unsigned long Result::columnCount() throw( std::exception )
+	unsigned long Result::columnCount() noexcept(false)
 	{
 		return m_impl->columnCount();
 	}
 
 
 
-	unsigned long Result::columnPos( const string& name ) throw( std::exception )
+	unsigned long Result::columnPos( const string& name ) noexcept(false)
 	{
 		return m_impl->columnPos( name );
 	}
 
 
 
-	const string Result::columnName( unsigned long pos ) throw( std::exception )
+	const string Result::columnName( unsigned long pos ) noexcept(false)
 	{
 		return m_impl->columnName( pos );
 	}
 
 
 
-	odbxtype Result::columnType( unsigned long pos ) throw( std::exception )
+	odbxtype Result::columnType( unsigned long pos ) noexcept(false)
 	{
 		return m_impl->columnType( pos );
 	}
 
 
 
-	unsigned long Result::fieldLength( unsigned long pos ) throw( std::exception )
+	unsigned long Result::fieldLength( unsigned long pos ) noexcept(false)
 	{
 		return m_impl->fieldLength( pos );
 	}
 
 
 
-	const char* Result::fieldValue( unsigned long pos ) throw( std::exception )
+	const char* Result::fieldValue( unsigned long pos ) noexcept(false)
 	{
 		return m_impl->fieldValue( pos );
 	}
 
 
-	Lob Result::getLob( const char* value ) throw( std::exception )
+	Lob Result::getLob( const char* value ) noexcept(false)
 	{
 		return m_impl->getLob( value );
 	}
@@ -288,7 +288,7 @@ namespace OpenDBX
 
 
 
-	Stmt::Stmt( Stmt_Iface* impl ) throw( std::exception )
+	Stmt::Stmt( Stmt_Iface* impl ) noexcept(false)
 	{
 		m_impl = impl;
 		m_ref = new int;
@@ -363,7 +363,7 @@ namespace OpenDBX
 
 
 
-	Result Stmt::execute() throw( std::exception )
+	Result Stmt::execute() noexcept(false)
 	{
 		return Result( m_impl->execute() );
 	}
@@ -384,7 +384,7 @@ namespace OpenDBX
 	}
 
 
-	Conn::Conn( const char* backend, const char* host, const char* port ) throw( std::exception )
+	Conn::Conn( const char* backend, const char* host, const char* port ) noexcept(false)
 	{
 		m_impl = new Conn_Impl( backend, host, port );
 		m_ref = new int;
@@ -393,7 +393,7 @@ namespace OpenDBX
 	}
 
 
-	Conn::Conn( const string& backend, const string& host, const string& port ) throw( std::exception )
+	Conn::Conn( const string& backend, const string& host, const string& port ) noexcept(false)
 	{
 		m_impl = new Conn_Impl( backend.c_str(), host.c_str(), port.c_str() );
 		m_ref = new int;
@@ -454,7 +454,7 @@ namespace OpenDBX
 
 
 
-	void Conn::bind( const char* database, const char* who, const char* cred, odbxbind method ) throw( std::exception )
+	void Conn::bind( const char* database, const char* who, const char* cred, odbxbind method ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -466,7 +466,7 @@ namespace OpenDBX
 
 
 
-	void Conn::bind( const string& database, const string& who, const string& cred, odbxbind method ) throw( std::exception )
+	void Conn::bind( const string& database, const string& who, const string& cred, odbxbind method ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -478,7 +478,7 @@ namespace OpenDBX
 
 
 
-	void Conn::unbind() throw( std::exception )
+	void Conn::unbind() noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -490,7 +490,7 @@ namespace OpenDBX
 
 
 
-	void Conn::finish() throw( std::exception )
+	void Conn::finish() noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -502,7 +502,7 @@ namespace OpenDBX
 
 
 
-	bool Conn::getCapability( odbxcap cap ) throw( std::exception )
+	bool Conn::getCapability( odbxcap cap ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -514,7 +514,7 @@ namespace OpenDBX
 
 
 
-	void Conn::getOption( odbxopt option, void* value ) throw( std::exception )
+	void Conn::getOption( odbxopt option, void* value ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -526,7 +526,7 @@ namespace OpenDBX
 
 
 
-	void Conn::setOption( odbxopt option, void* value ) throw( std::exception )
+	void Conn::setOption( odbxopt option, void* value ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -538,7 +538,7 @@ namespace OpenDBX
 
 
 
-	string& Conn::escape( const string& from, string& to ) throw( std::exception )
+	string& Conn::escape( const string& from, string& to ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -550,7 +550,7 @@ namespace OpenDBX
 
 
 
-	string& Conn::escape( const char* from, unsigned long fromlen, string& to ) throw( std::exception )
+	string& Conn::escape( const char* from, unsigned long fromlen, string& to ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{
@@ -562,7 +562,7 @@ namespace OpenDBX
 
 
 
-	Stmt Conn::create( const char* sql, unsigned long length, Stmt::Type type ) throw( std::exception )
+	Stmt Conn::create( const char* sql, unsigned long length, Stmt::Type type ) noexcept(false)
 	{
 		if( length == 0 ) { length = (unsigned long) strlen( sql ); }
 
@@ -571,7 +571,7 @@ namespace OpenDBX
 
 
 
-	Stmt Conn::create( const string& sql, Stmt::Type type ) throw( std::exception )
+	Stmt Conn::create( const string& sql, Stmt::Type type ) noexcept(false)
 	{
 		if( m_impl == NULL )
 		{

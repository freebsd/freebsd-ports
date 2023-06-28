--- lib/odbx_impl.cpp.orig	2012-06-10 21:20:25 UTC
+++ lib/odbx_impl.cpp
@@ -29,7 +29,7 @@ namespace OpenDBX
 	*  OpenDBX large object implementation
 	*/
 
-	Lob_Impl::Lob_Impl( odbx_result_t* result, const char* value ) throw( std::exception )
+	Lob_Impl::Lob_Impl( odbx_result_t* result, const char* value ) noexcept(false)
 	{
 		int err;
 
@@ -52,7 +52,7 @@ namespace OpenDBX
 
 
 
-	void Lob_Impl::close() throw( std::exception )
+	void Lob_Impl::close() noexcept(false)
 	{
 		int err;
 
@@ -66,7 +66,7 @@ namespace OpenDBX
 
 
 
-	ssize_t Lob_Impl::read( void* buffer, size_t buflen ) throw( std::exception )
+	ssize_t Lob_Impl::read( void* buffer, size_t buflen ) noexcept(false)
 	{
 		ssize_t err;
 
@@ -80,7 +80,7 @@ namespace OpenDBX
 
 
 
-	ssize_t Lob_Impl::write( void* buffer, size_t buflen ) throw( std::exception )
+	ssize_t Lob_Impl::write( void* buffer, size_t buflen ) noexcept(false)
 	{
 		ssize_t err;
 
@@ -102,7 +102,7 @@ namespace OpenDBX
 
 
 
-	Result_Impl::Result_Impl( odbx_t* handle ) throw( std::exception )
+	Result_Impl::Result_Impl( odbx_t* handle ) noexcept(false)
 	{
 		m_handle = handle;
 		m_result = NULL;
@@ -121,7 +121,7 @@ namespace OpenDBX
 
 
 
-	void Result_Impl::finish() throw( std::exception )
+	void Result_Impl::finish() noexcept(false)
 	{
 		odbxres res;
 
@@ -137,7 +137,7 @@ namespace OpenDBX
 
 
 
-	odbxres Result_Impl::getResult( struct timeval* timeout, unsigned long chunk ) throw( std::exception )
+	odbxres Result_Impl::getResult( struct timeval* timeout, unsigned long chunk ) noexcept(false)
 	{
 		int err;
 
@@ -162,7 +162,7 @@ namespace OpenDBX
 
 
 
-	odbxrow Result_Impl::getRow() throw( std::exception )
+	odbxrow Result_Impl::getRow() noexcept(false)
 	{
 		int err;
 
@@ -176,21 +176,21 @@ namespace OpenDBX
 
 
 
-	uint64_t Result_Impl::rowsAffected() throw( std::exception )
+	uint64_t Result_Impl::rowsAffected() noexcept(false)
 	{
 		return odbx_rows_affected( m_result );
 	}
 
 
 
-	unsigned long Result_Impl::columnCount() throw( std::exception )
+	unsigned long Result_Impl::columnCount() noexcept(false)
 	{
 		return odbx_column_count( m_result );
 	}
 
 
 
-	unsigned long Result_Impl::columnPos( const string& name ) throw( std::exception )
+	unsigned long Result_Impl::columnPos( const string& name ) noexcept(false)
 	{
 		map<const string, unsigned long>::const_iterator it;
 
@@ -213,7 +213,7 @@ namespace OpenDBX
 
 
 
-	const string Result_Impl::columnName( unsigned long pos ) throw( std::exception )
+	const string Result_Impl::columnName( unsigned long pos ) noexcept(false)
 	{
 		if( pos < odbx_column_count( m_result ) )
 		{
@@ -230,7 +230,7 @@ namespace OpenDBX
 
 
 
-	odbxtype Result_Impl::columnType( unsigned long pos ) throw( std::exception )
+	odbxtype Result_Impl::columnType( unsigned long pos ) noexcept(false)
 	{
 		if( pos < odbx_column_count( m_result ) )
 		{
@@ -242,7 +242,7 @@ namespace OpenDBX
 
 
 
-	unsigned long Result_Impl::fieldLength( unsigned long pos ) throw( std::exception )
+	unsigned long Result_Impl::fieldLength( unsigned long pos ) noexcept(false)
 	{
 		if( pos < odbx_column_count( m_result ) )
 		{
@@ -254,7 +254,7 @@ namespace OpenDBX
 
 
 
-	const char* Result_Impl::fieldValue( unsigned long pos ) throw( std::exception )
+	const char* Result_Impl::fieldValue( unsigned long pos ) noexcept(false)
 	{
 		if( pos < odbx_column_count( m_result ) )
 		{
@@ -265,7 +265,7 @@ namespace OpenDBX
 	}
 
 
-	Lob_Iface* Result_Impl::getLob( const char* value ) throw( std::exception )
+	Lob_Iface* Result_Impl::getLob( const char* value ) noexcept(false)
 	{
 		return new Lob_Impl( m_result, value );
 	}
@@ -280,7 +280,7 @@ namespace OpenDBX
 
 
 
-	Stmt_Impl::Stmt_Impl( odbx_t* handle ) throw( std::exception )
+	Stmt_Impl::Stmt_Impl( odbx_t* handle ) noexcept(false)
 	{
 		m_handle = handle;
 	}
@@ -301,7 +301,7 @@ namespace OpenDBX
 
 
 
-	StmtSimple_Impl::StmtSimple_Impl( odbx_t* handle, const string& sql ) throw( std::exception ) : Stmt_Impl( handle )
+	StmtSimple_Impl::StmtSimple_Impl( odbx_t* handle, const string& sql ) noexcept(false) : Stmt_Impl( handle )
 	{
 		m_sql = sql;
 /*		m_buffer = NULL;
@@ -326,7 +326,7 @@ namespace OpenDBX
 
 
 
-	StmtSimple_Impl::StmtSimple_Impl() throw( std::exception ) : Stmt_Impl( NULL )
+	StmtSimple_Impl::StmtSimple_Impl() noexcept(false) : Stmt_Impl( NULL )
 	{
 // 		m_buffer = NULL;
 // 		m_bufsize = 0;
@@ -365,7 +365,7 @@ namespace OpenDBX
 
 
 
-	Result_Iface* StmtSimple_Impl::execute() throw( std::exception )
+	Result_Iface* StmtSimple_Impl::execute() noexcept(false)
 	{
 // 		if( m_binds.size() ) { _exec_params(); }
 // 		else { _exec_noparams(); }
@@ -377,7 +377,7 @@ namespace OpenDBX
 
 
 
-	inline void StmtSimple_Impl::_exec_noparams() throw( std::exception )
+	inline void StmtSimple_Impl::_exec_noparams() noexcept(false)
 	{
 		int err;
 
@@ -452,7 +452,7 @@ namespace OpenDBX
 
 
 
-	Conn_Impl::Conn_Impl( const char* backend, const char* host, const char* port ) throw( std::exception )
+	Conn_Impl::Conn_Impl( const char* backend, const char* host, const char* port ) noexcept(false)
 	{
 		int err;
 
@@ -480,7 +480,7 @@ namespace OpenDBX
 
 
 
-	void Conn_Impl::bind( const char* database, const char* who, const char* cred, odbxbind method ) throw( std::exception )
+	void Conn_Impl::bind( const char* database, const char* who, const char* cred, odbxbind method ) noexcept(false)
 	{
 		int err;
 
@@ -494,7 +494,7 @@ namespace OpenDBX
 
 
 
-	void Conn_Impl::unbind() throw( std::exception )
+	void Conn_Impl::unbind() noexcept(false)
 	{
 		int err;
 
@@ -508,7 +508,7 @@ namespace OpenDBX
 
 
 
-	void Conn_Impl::finish() throw( std::exception )
+	void Conn_Impl::finish() noexcept(false)
 	{
 		int err;
 
@@ -528,7 +528,7 @@ namespace OpenDBX
 
 
 
-	bool Conn_Impl::getCapability( odbxcap cap ) throw( std::exception )
+	bool Conn_Impl::getCapability( odbxcap cap ) noexcept(false)
 	{
 		int err = odbx_capabilities( m_handle, (unsigned int) cap );
 
@@ -545,7 +545,7 @@ namespace OpenDBX
 
 
 
-	void Conn_Impl::getOption( odbxopt option, void* value ) throw( std::exception )
+	void Conn_Impl::getOption( odbxopt option, void* value ) noexcept(false)
 	{
 		int err;
 
@@ -557,7 +557,7 @@ namespace OpenDBX
 
 
 
-	void Conn_Impl::setOption( odbxopt option, void* value ) throw( std::exception )
+	void Conn_Impl::setOption( odbxopt option, void* value ) noexcept(false)
 	{
 		int err;
 
@@ -569,7 +569,7 @@ namespace OpenDBX
 
 
 
-	string& Conn_Impl::escape( const char* from, unsigned long fromlen, string& to ) throw( std::exception )
+	string& Conn_Impl::escape( const char* from, unsigned long fromlen, string& to ) noexcept(false)
 	{
 		int err;
 		unsigned long size = m_escsize;
@@ -594,7 +594,7 @@ namespace OpenDBX
 
 
 
-	Stmt_Iface* Conn_Impl::create( const string& sql, Stmt::Type type ) throw( std::exception )
+	Stmt_Iface* Conn_Impl::create( const string& sql, Stmt::Type type ) noexcept(false)
 	{
 		switch( type )
 		{
@@ -607,7 +607,7 @@ namespace OpenDBX
 
 
 
-	inline char* Conn_Impl::_resize( char* buffer, size_t size ) throw( std::exception )
+	inline char* Conn_Impl::_resize( char* buffer, size_t size ) noexcept(false)
 	{
 		if( ( buffer = (char*) std::realloc( buffer, size ) ) == NULL )
 		{

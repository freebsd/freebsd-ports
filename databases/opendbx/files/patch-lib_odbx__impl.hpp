--- lib/odbx_impl.hpp.orig	2010-08-01 02:08:41 UTC
+++ lib/odbx_impl.hpp
@@ -37,13 +37,13 @@ namespace OpenDBX
 
 	public:
 
-		Lob_Impl( odbx_result_t* result, const char* value ) throw( std::exception );
+		Lob_Impl( odbx_result_t* result, const char* value ) noexcept(false);
 		~Lob_Impl() throw();
 
-		void close() throw( std::exception );
+		void close() noexcept(false);
 
-		ssize_t read( void* buffer, size_t buflen ) throw( std::exception );
-		ssize_t write( void* buffer, size_t buflen ) throw( std::exception );
+		ssize_t read( void* buffer, size_t buflen ) noexcept(false);
+		ssize_t write( void* buffer, size_t buflen ) noexcept(false);
 	};
 
 
@@ -56,25 +56,25 @@ namespace OpenDBX
 
 	public:
 
-		Result_Impl( odbx_t* handle ) throw( std::exception );
+		Result_Impl( odbx_t* handle ) noexcept(false);
 		~Result_Impl() throw();
 
-		void finish() throw( std::exception );
+		void finish() noexcept(false);
 
-		odbxres getResult( struct timeval* timeout, unsigned long chunk ) throw( std::exception );
+		odbxres getResult( struct timeval* timeout, unsigned long chunk ) noexcept(false);
 
-		odbxrow getRow() throw( std::exception );
-		uint64_t rowsAffected() throw( std::exception );
+		odbxrow getRow() noexcept(false);
+		uint64_t rowsAffected() noexcept(false);
 
-		unsigned long columnCount() throw( std::exception );
-		unsigned long columnPos( const string& name ) throw( std::exception );
-		const string columnName( unsigned long pos ) throw( std::exception );
-		odbxtype columnType( unsigned long pos ) throw( std::exception );
+		unsigned long columnCount() noexcept(false);
+		unsigned long columnPos( const string& name ) noexcept(false);
+		const string columnName( unsigned long pos ) noexcept(false);
+		odbxtype columnType( unsigned long pos ) noexcept(false);
 
-		unsigned long fieldLength( unsigned long pos ) throw( std::exception );
-		const char* fieldValue( unsigned long pos ) throw( std::exception );
+		unsigned long fieldLength( unsigned long pos ) noexcept(false);
+		const char* fieldValue( unsigned long pos ) noexcept(false);
 
-		Lob_Iface* getLob( const char* value ) throw( std::exception );
+		Lob_Iface* getLob( const char* value ) noexcept(false);
 	};
 
 
@@ -89,7 +89,7 @@ namespace OpenDBX
 
 	public:
 
-		Stmt_Impl( odbx_t* handle ) throw( std::exception );
+		Stmt_Impl( odbx_t* handle ) noexcept(false);
 	};
 
 
@@ -106,19 +106,19 @@ namespace OpenDBX
 
 	protected:
 
-// 		inline void _exec_params() throw( std::exception );
-		inline void _exec_noparams() throw( std::exception );
+// 		inline void _exec_params() noexcept(false);
+		inline void _exec_noparams() noexcept(false);
 
 	public:
 
-		StmtSimple_Impl( odbx_t* handle, const string& sql ) throw( std::exception );
-		StmtSimple_Impl() throw( std::exception );
+		StmtSimple_Impl( odbx_t* handle, const string& sql ) noexcept(false);
+		StmtSimple_Impl() noexcept(false);
 		~StmtSimple_Impl() throw();
 
 // 		void bind( const void* data, unsigned long size, size_t pos, int flags );
 // 		size_t count();
 
-		Result_Iface* execute() throw( std::exception );
+		Result_Iface* execute() noexcept(false);
 	};
 
 
@@ -132,25 +132,25 @@ namespace OpenDBX
 
 	protected:
 
-		inline char* _resize( char* buffer, size_t size ) throw( std::exception );
+		inline char* _resize( char* buffer, size_t size ) noexcept(false);
 
 	public:
 
-		Conn_Impl( const char* backend, const char* host, const char* port ) throw( std::exception );
+		Conn_Impl( const char* backend, const char* host, const char* port ) noexcept(false);
 		~Conn_Impl() throw();
-		void finish() throw( std::exception );
+		void finish() noexcept(false);
 
-		void bind( const char* database, const char* who, const char* cred, odbxbind method = ODBX_BIND_SIMPLE ) throw( std::exception );
-		void unbind() throw( std::exception );
+		void bind( const char* database, const char* who, const char* cred, odbxbind method = ODBX_BIND_SIMPLE ) noexcept(false);
+		void unbind() noexcept(false);
 
-		bool getCapability( odbxcap cap ) throw( std::exception );
+		bool getCapability( odbxcap cap ) noexcept(false);
 
-		void getOption( odbxopt option, void* value ) throw( std::exception );
-		void setOption( odbxopt option, void* value ) throw( std::exception );
+		void getOption( odbxopt option, void* value ) noexcept(false);
+		void setOption( odbxopt option, void* value ) noexcept(false);
 
-		string& escape( const char* from, unsigned long fromlen, string& to ) throw( std::exception );
+		string& escape( const char* from, unsigned long fromlen, string& to ) noexcept(false);
 
-		Stmt_Iface* create( const string& sql, Stmt::Type type ) throw( std::exception );
+		Stmt_Iface* create( const string& sql, Stmt::Type type ) noexcept(false);
 	};
 
 }   // namespace

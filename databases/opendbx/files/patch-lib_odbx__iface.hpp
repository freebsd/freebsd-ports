--- lib/odbx_iface.hpp.orig	2010-08-01 02:08:41 UTC
+++ lib/odbx_iface.hpp
@@ -27,10 +27,10 @@ namespace OpenDBX
 	public:
 
 		virtual ~Lob_Iface() throw() {}
-		virtual void close() throw( std::exception ) = 0;
+		virtual void close() noexcept(false) = 0;
 
-		virtual ssize_t read( void* buffer, size_t buflen ) throw( std::exception ) = 0;
-		virtual ssize_t write( void* buffer, size_t buflen ) throw( std::exception ) = 0;
+		virtual ssize_t read( void* buffer, size_t buflen ) noexcept(false) = 0;
+		virtual ssize_t write( void* buffer, size_t buflen ) noexcept(false) = 0;
 	};
 
 
@@ -40,22 +40,22 @@ namespace OpenDBX
 	public:
 
 		virtual ~Result_Iface() throw() {}
-		virtual void finish() throw( std::exception ) = 0;
+		virtual void finish() noexcept(false) = 0;
 
-		virtual odbxres getResult( struct timeval* timeout, unsigned long chunk ) throw( std::exception ) = 0;
+		virtual odbxres getResult( struct timeval* timeout, unsigned long chunk ) noexcept(false) = 0;
 
-		virtual odbxrow getRow() throw( std::exception ) = 0;
-		virtual uint64_t rowsAffected() throw( std::exception ) = 0;
+		virtual odbxrow getRow() noexcept(false) = 0;
+		virtual uint64_t rowsAffected() noexcept(false) = 0;
 
-		virtual unsigned long columnCount() throw( std::exception ) = 0;
-		virtual unsigned long columnPos( const string& name ) throw( std::exception ) = 0;
-		virtual const string columnName( unsigned long pos ) throw( std::exception ) = 0;
-		virtual odbxtype columnType( unsigned long pos ) throw( std::exception ) = 0;
+		virtual unsigned long columnCount() noexcept(false) = 0;
+		virtual unsigned long columnPos( const string& name ) noexcept(false) = 0;
+		virtual const string columnName( unsigned long pos ) noexcept(false) = 0;
+		virtual odbxtype columnType( unsigned long pos ) noexcept(false) = 0;
 
-		virtual unsigned long fieldLength( unsigned long pos ) throw( std::exception ) = 0;
-		virtual const char* fieldValue( unsigned long pos ) throw( std::exception ) = 0;
+		virtual unsigned long fieldLength( unsigned long pos ) noexcept(false) = 0;
+		virtual const char* fieldValue( unsigned long pos ) noexcept(false) = 0;
 
-		virtual Lob_Iface* getLob( const char* value ) throw( std::exception ) = 0;
+		virtual Lob_Iface* getLob( const char* value ) noexcept(false) = 0;
 	};
 
 
@@ -65,7 +65,7 @@ namespace OpenDBX
 	public:
 
 		virtual ~Stmt_Iface() throw() {};
-		virtual Result_Iface* execute() throw( std::exception ) = 0;
+		virtual Result_Iface* execute() noexcept(false) = 0;
 
 // 		virtual void bind( const void* data, unsigned long size, size_t pos, int flags ) = 0;
 // 		virtual size_t count() = 0;
@@ -78,19 +78,19 @@ namespace OpenDBX
 	public:
 
 		virtual ~Conn_Iface() throw() {};
-		virtual void finish() throw( std::exception ) = 0;
+		virtual void finish() noexcept(false) = 0;
 
-		virtual void bind( const char* database, const char* who, const char* cred, odbxbind method = ODBX_BIND_SIMPLE ) throw( std::exception ) = 0;
-		virtual void unbind() throw( std::exception ) = 0;
+		virtual void bind( const char* database, const char* who, const char* cred, odbxbind method = ODBX_BIND_SIMPLE ) noexcept(false) = 0;
+		virtual void unbind() noexcept(false) = 0;
 
-		virtual bool getCapability( odbxcap cap ) throw( std::exception ) = 0;
+		virtual bool getCapability( odbxcap cap ) noexcept(false) = 0;
 
-		virtual void getOption( odbxopt option, void* value ) throw( std::exception ) = 0;
-		virtual void setOption( odbxopt option, void* value ) throw( std::exception ) = 0;
+		virtual void getOption( odbxopt option, void* value ) noexcept(false) = 0;
+		virtual void setOption( odbxopt option, void* value ) noexcept(false) = 0;
 
-		virtual string& escape( const char* from, unsigned long fromlen, string& to ) throw( std::exception ) = 0;
+		virtual string& escape( const char* from, unsigned long fromlen, string& to ) noexcept(false) = 0;
 
-		virtual Stmt_Iface* create( const string& sql, Stmt::Type type ) throw( std::exception ) = 0;
+		virtual Stmt_Iface* create( const string& sql, Stmt::Type type ) noexcept(false) = 0;
 	};
 
 }   // namespace

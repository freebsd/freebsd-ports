--- ./connectivity/source/commontools/dbexception.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/commontools/dbexception.cxx	2012-07-18 13:24:25.000000000 -0400
@@ -144,7 +144,7 @@
 //------------------------------------------------------------------------------
 SQLExceptionInfo::SQLExceptionInfo(const staruno::Any& _rError)
 {
-    const staruno::Type& aSQLExceptionType = ::getCppuType(reinterpret_cast< ::com::sun::star::sdbc::SQLException*>(NULL));
+    const staruno::Type& aSQLExceptionType = ::getCppuType(static_cast< ::com::sun::star::sdbc::SQLException*>(0));
     sal_Bool bValid = isAssignableFrom(aSQLExceptionType, _rError.getValueType());
     if (bValid)
         m_aContent = _rError;
@@ -158,9 +158,9 @@
 {
     staruno::Type aContentType = m_aContent.getValueType();
 
-    const Type& aSQLExceptionType = ::getCppuType( reinterpret_cast< SQLException* >( NULL ) );
-    const Type& aSQLWarningType = ::getCppuType( reinterpret_cast< SQLWarning* >( NULL ) );
-    const Type& aSQLContextType  = ::getCppuType( reinterpret_cast< SQLContext* >( NULL ) );
+    const Type& aSQLExceptionType = ::getCppuType( static_cast< SQLException* >( 0 ) );
+    const Type& aSQLWarningType = ::getCppuType( static_cast< SQLWarning* >( 0 ) );
+    const Type& aSQLContextType  = ::getCppuType( static_cast< SQLContext* >( 0 ) );
 
     if ( isAssignableFrom( aSQLContextType, m_aContent.getValueType() ) )
         m_eType = SQL_CONTEXT;

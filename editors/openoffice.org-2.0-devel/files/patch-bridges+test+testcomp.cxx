--- ../bridges/test/testcomp.cxx.orig	Wed Mar 12 17:40:53 2003
+++ ../bridges/test/testcomp.cxx	Wed Mar 12 17:42:54 2003
@@ -2,9 +2,9 @@
  *
  *  $RCSfile: testcomp.cxx,v $
  *
- *  $Revision: 1.2 $
+ *  $Revision: 1.2.54.1 $
  *
- *  last change: $Author: jl $ $Date: 2001/03/14 09:25:39 $
+ *  last change: $Author: mh $ $Date: 2003/03/12 09:23:15 $
  *
  *  The Contents of this file are made available subject to the terms of
  *  either of the following licenses
@@ -125,7 +125,7 @@
 	}
 }
 
-Any OInstanceProvider::queryInterface( const  Type & aType )
+Any OInstanceProvider::queryInterface( const  Type & aType ) throw ( RuntimeException )
 {
 	Any a = ::cppu::queryInterface( aType , 
 			SAL_STATIC_CAST( XInstanceProvider * , this ) );
@@ -192,9 +192,9 @@
 		}
 		return aRet;
 	}
-    virtual void SAL_CALL acquire() throw(::com::sun::star::uno::RuntimeException)
+    virtual void SAL_CALL acquire() throw()
 		{ osl_incrementInterlockedCount( &_nRef ); }
-    virtual void SAL_CALL release() throw(::com::sun::star::uno::RuntimeException)
+    virtual void SAL_CALL release() throw()
 		{ if (! osl_decrementInterlockedCount( &_nRef )) delete this; }
 	
 	// XServiceInfo
@@ -325,7 +325,7 @@
  *
  *****************/
 
-Any OCallMe::queryInterface( const  Type & aType )
+Any OCallMe::queryInterface( const  Type & aType )  throw ( RuntimeException )
 {
 	Any a = ::cppu::queryInterface( aType,
 			SAL_STATIC_CAST( XCallMe * , this ) );
@@ -421,7 +421,7 @@
  * OInterfaceTest
  *
  *******************/
-Any OInterfaceTest::queryInterface( const Type & aType )
+Any OInterfaceTest::queryInterface( const Type & aType )  throw ( RuntimeException )
 {
 	Any a = ::cppu::queryInterface( aType,
 			SAL_STATIC_CAST( XInterfaceTest * , this ) );
@@ -473,7 +473,7 @@
 }
 
 
-Any OTestFactory::queryInterface( const Type & aType )
+Any OTestFactory::queryInterface( const Type & aType )  throw ( RuntimeException )
 {
 	Any a = ::cppu::queryInterface( aType,
 			SAL_STATIC_CAST( XTestFactory * , this ) );
@@ -500,42 +500,6 @@
 
 
 
-/********************************************************
- *
- ********************************************************/
-/*Any OConnectCallback::queryInterface( const Type & aType )
-{
-	Any a = ::cppu::queryInterface( aType,
-			SAL_STATIC_CAST( XConnectCallback * , this ) );
-	if( a.hasValue() )
-    {
-	    return a;
-	}
-	return OWeakObject::queryInterface( aType );
-}
-
-
-void SAL_CALL OConnectCallback::attemptConnect(
-		const Reference< XConnectionServerSide >& connection )
-		throw(SecurityException, ::com::sun::star::uno::RuntimeException)
-{
-	// TODO
-	// user verification
-	if( L"bad guy" == connection->getUser() &&
-		L"secret" == connection->getPassword() )
-	{
-		Reference< XInterface > rInterface(
-			( XInterface * ) (::cppu::OWeakObject *) new OTestFactory() );
-		connection->provideRemoteObject( rInterface );
-	}
-	else
-	{
-		throw SecurityException();
-	}
-}
-
-*/
-
 
 //  class OInstanceProvider :
 //  	public ::cppu::OWeakObject,
@@ -551,7 +515,6 @@
 //  	void 		SAL_CALL release() 						 { OWeakObject::release(); }
 	
 //  public:
-//  	// XConnectCallback
 //      virtual ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface > SAL_CALL
 //  	       getInstance( const ::rtl::OUString& sObjectName )
 //  		         throw( ::com::sun::star::container::NoSuchElementException,

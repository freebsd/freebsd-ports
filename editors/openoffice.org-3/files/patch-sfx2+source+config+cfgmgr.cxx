Wired bug?
http://qa.openoffice.org/issues/show_bug.cgi?id=22253

--- ../sfx2/source/config/cfgmgr.cxx.org	Fri Nov  7 19:11:25 2003
+++ ../sfx2/source/config/cfgmgr.cxx	Fri Nov  7 19:30:26 2003
@@ -118,6 +118,10 @@
 		catch(com::sun::star::ucb::InteractiveAugmentedIOException&)
 		{
 		}
+		// PJ: This is a workaround for weird error on FreeBSD (#i22253#)
+		catch(com::sun::star::uno::Exception&)
+		{
+		}
 		sal_Bool bIsDocument;
 		if ( (aAny >>= bIsDocument) && bIsDocument )
 			return new SotStorage( TRUE, rName, nMode, STORAGE_TRANSACTED );

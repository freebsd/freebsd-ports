--- src/kernel/stateupdater.cc.orig	2009-09-11 12:02:56 UTC
+++ src/kernel/stateupdater.cc
@@ -1227,7 +1227,7 @@ bool checkAndFixOperator (const StateUpd
 			{ // Convert it to real
 				double dval = 0.0;
 				dval = IProperty::getSmartCObjectPtr<CInt>(*it)->getValue();
-				shared_ptr<IProperty> pIp (new CReal (dval));
+				boost::shared_ptr<IProperty> pIp (new CReal (dval));
 				std::replace (operands.begin(), operands.end(), *it, pIp);
 			}
 		}

--- src/kernel/stateupdater.cc.orig	2016-06-11 06:44:12.114485000 +0900
+++ src/kernel/stateupdater.cc	2016-06-11 06:45:25.066472000 +0900
@@ -1227,7 +1227,7 @@
 			{ // Convert it to real
 				double dval = 0.0;
 				dval = IProperty::getSmartCObjectPtr<CInt>(*it)->getValue();
-				shared_ptr<IProperty> pIp (new CReal (dval));
+				boost::shared_ptr<IProperty> pIp (new CReal (dval));
 				std::replace (operands.begin(), operands.end(), *it, pIp);
 			}
 		}

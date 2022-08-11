--- src/kernel/stateupdater.cc.orig	2009-09-11 12:02:56 UTC
+++ src/kernel/stateupdater.cc
@@ -1207,7 +1207,7 @@ bool checkAndFixOperator (const StateUpdater::CheckTyp
 	PdfOperator::Operands::reverse_iterator rit = operands.rbegin ();
 	// Be careful -- buffer overflow
 	argNum = std::min (argNum, operands.size());
-	advance (rit, argNum);
+	boost::advance (rit, argNum);
 	PdfOperator::Operands::iterator it = rit.base ();
 	// Loop from the first operator to the end
 	for (int pos = 0; it != operands.end (); ++it, ++pos)
@@ -1227,7 +1227,7 @@ bool checkAndFixOperator (const StateUpdater::CheckTyp
 			{ // Convert it to real
 				double dval = 0.0;
 				dval = IProperty::getSmartCObjectPtr<CInt>(*it)->getValue();
-				shared_ptr<IProperty> pIp (new CReal (dval));
+				boost::shared_ptr<IProperty> pIp (new CReal (dval));
 				std::replace (operands.begin(), operands.end(), *it, pIp);
 			}
 		}

--- src/items/resistor.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/items/resistor.cpp
@@ -260,7 +260,7 @@ bool Resistor::collectExtraInfo(QWidget * parent, cons
 		validator->setSymbol(OhmSymbol);
 		validator->setConverter(TextUtils::convertFromPowerPrefix);
 		validator->setBounds(MIN_RESISTANCE, MAX_RESISTANCE);
-		validator->setRegularExpression(QRegularExpression(QString("((\\d{1,10})|(\\d{1,10}\\.)|(\\d{1,10}\\.\\d{1,5}))[\\x%1umkMG]{0,1}[\\x03A9]{0,1}").arg(TextUtils::MicroSymbolCode, 4, 16, QChar('0'))));
+		validator->setRegularExpression(QRegularExpression(QString("((\\d{1,10})|(\\d{1,10}\\.)|(\\d{1,10}\\.\\d{1,5}))[\\x%1umkMG]{0,1}[\\x03A9]{0,1}").arg(static_cast<int>(TextUtils::MicroSymbolCode), 4, 16, QChar('0'))));
 		focusOutComboBox->setValidator(validator);
 		connect(focusOutComboBox->validator(), SIGNAL(sendState(QValidator::State)), this, SLOT(textModified(QValidator::State)));
 		connect(focusOutComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(resistanceEntry(int)));

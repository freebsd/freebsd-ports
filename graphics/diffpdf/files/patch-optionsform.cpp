--- optionsform.cpp.orig	2013-10-15 07:01:22 UTC
+++ optionsform.cpp
@@ -76,9 +76,9 @@ void OptionsForm::createWidgets()
             << qMakePair(tr("Diagonal \\"), Qt::FDiagPattern)
             << qMakePair(tr("Diagonal Cross"), Qt::DiagCrossPattern))
         brushStyleComboBox->addItem(brushSwatch(pair.second, color),
-                                                pair.first, pair.second);
+                                                pair.first, QVariant::fromValue(pair.second));
     brushStyleComboBox->setCurrentIndex(brushStyleComboBox->findData(
-                brush.style()));
+                QVariant::fromValue(brush.style())));
 
     penStyleComboBox = new QComboBox;
     typedef QPair<QString, Qt::PenStyle> PenPair;
@@ -90,9 +90,9 @@ void OptionsForm::createWidgets()
             << qMakePair(tr("Dash-Dotted"), Qt::DashDotLine)
             << qMakePair(tr("Dash-Dot-Dotted"), Qt::DashDotDotLine))
         penStyleComboBox->addItem(penStyleSwatch(pair.second, color),
-                                  pair.first, pair.second);
+                                  pair.first, QVariant::fromValue(pair.second));
     penStyleComboBox->setCurrentIndex(penStyleComboBox->findData(
-                pen.style()));
+                QVariant::fromValue(pen.style())));
 
     alphaSpinBox = new QSpinBox;
     alphaSpinBox->setRange(1, 100);

--- src/fractalgenerator.cc.orig	2020-10-10 15:10:01 UTC
+++ src/fractalgenerator.cc
@@ -128,7 +128,7 @@ FractalGeneratorApp::FractalGeneratorApp(QWidget* pare
    helpMenu->addAction(tr("&About"), this, SLOT(slotHelpAbout()));
 
    Printer.setColorMode(QPrinter::Color);
-   Printer.setOrientation(QPrinter::Landscape);
+   Printer.setPageOrientation(QPageLayout::Landscape);
    Printer.setOutputFileName(tr("Fractal.pdf"));
 
    statusBar()->showMessage(tr("Welcome to FractGen!"), 3000);

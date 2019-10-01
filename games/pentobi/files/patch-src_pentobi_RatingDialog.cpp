--- src/pentobi/RatingDialog.cpp.orig	2019-09-01 15:41:49 UTC
+++ src/pentobi/RatingDialog.cpp
@@ -56,11 +56,11 @@ RatingDialog::RatingDialog(QWidget* parent, RatingHist
     formLayout->addRow(tr("Rated games:"), m_labelNuGames);
     m_labelBestRating = createSelectableLabel();
     formLayout->addRow(tr("Best previous rating:"), m_labelBestRating);
-    layout->addSpacing(layout->margin());
+    layout->addSpacing(layout->spacing());
     layout->addWidget(new QLabel(tr("Recent development:")));
     m_graph = new RatingGraph;
     layout->addWidget(m_graph, 1);
-    layout->addSpacing(layout->margin());
+    layout->addSpacing(layout->spacing());
     layout->addWidget(new QLabel(tr("Recent games:")));
     m_list = new RatedGamesList;
     layout->addWidget(m_list, 1);

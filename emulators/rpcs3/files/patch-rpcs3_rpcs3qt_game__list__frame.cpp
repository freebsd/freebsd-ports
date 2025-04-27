Fix build with Qt >= 6.9.0

Backported from: https://github.com/RPCS3/rpcs3/commit/600e4604169464c64cbf548e7629e483ad2aad1e

--- rpcs3/rpcs3qt/game_list_frame.cpp.orig	2025-03-30 19:45:32 UTC
+++ rpcs3/rpcs3qt/game_list_frame.cpp
@@ -2363,7 +2363,7 @@ void game_list_frame::BatchActionBySerials(progress_di
 
 		connect(future_watcher, &QFutureWatcher<void>::finished, this, [=, this]()
 		{
-			pdlg->setLabelText(progressLabel.arg(*index).arg(serials_size));
+			pdlg->setLabelText(progressLabel.arg(index->load()).arg(serials_size));
 			pdlg->setCancelButtonText(tr("OK"));
 			QApplication::beep();
 
@@ -2396,7 +2396,7 @@ void game_list_frame::BatchActionBySerials(progress_di
 			return;
 		}
 
-		pdlg->setLabelText(progressLabel.arg(*index).arg(serials_size));
+		pdlg->setLabelText(progressLabel.arg(index->load()).arg(serials_size));
 		pdlg->setCancelButtonText(tr("OK"));
 		connect(pdlg, &progress_dialog::canceled, this, [pdlg](){ pdlg->deleteLater(); });
 		QApplication::beep();

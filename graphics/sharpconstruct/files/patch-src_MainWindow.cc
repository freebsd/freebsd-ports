--- src/MainWindow.cc.orig	2006-01-02 10:18:20 UTC
+++ src/MainWindow.cc
@@ -792,7 +792,7 @@ void MainWindow::on_speed_test_clicked_(
 			output += ToString( times[ i ] ) + " seconds\n";
 			adder += times[ i ];
 		}
-		Gtk::MessageDialog::MessageDialog( *mw, "Times:\n" + output +
+		Gtk::MessageDialog( *mw, "Times:\n" + output +
 						   "\nAverage: " + ToString( adder / runs ) +
 						   " seconds" ).run();
 	}
@@ -816,7 +816,7 @@ void MainWindow::on_speed_test_clicked_(
 		for( unsigned i = 0; i < runs; ++i )
 			editor_.event( (GdkEvent*)( &click ) );
 		timer.stop();
-		Gtk::MessageDialog::MessageDialog( *mw, ToString( timer.elapsed() ) + " seconds" ).run();	
+		Gtk::MessageDialog( *mw, ToString( timer.elapsed() ) + " seconds" ).run();	
 
 		/*em.type = GDK_MOTION_NOTIFY;
 		em.window = editor_.get_window()->gobj();

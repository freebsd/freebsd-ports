--- src/MainWindow.cc.orig	2013-10-02 09:31:18.000000000 +0000
+++ src/MainWindow.cc
@@ -786,7 +786,7 @@ void MainWindow::on_speed_test_clicked_(
 			output += ToString( times[ i ] ) + " seconds\n";
 			adder += times[ i ];
 		}
-		Gtk::MessageDialog::MessageDialog( *mw, "Times:\n" + output +
+		Gtk::MessageDialog( *mw, "Times:\n" + output +
 						   "\nAverage: " + ToString( adder / runs ) +
 						   " seconds" ).run();
 	}
@@ -810,7 +810,7 @@ void MainWindow::on_speed_test_clicked_(
 		for( unsigned i = 0; i < runs; ++i )
 			editor_.event( (GdkEvent*)( &click ) );
 		timer.stop();
-		Gtk::MessageDialog::MessageDialog( *mw, ToString( timer.elapsed() ) + " seconds" ).run();	
+		Gtk::MessageDialog( *mw, ToString( timer.elapsed() ) + " seconds" ).run();	
 
 		/*em.type = GDK_MOTION_NOTIFY;
 		em.window = editor_.get_window()->gobj();

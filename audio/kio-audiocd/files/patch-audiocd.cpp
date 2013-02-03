--- audiocd.cpp.orig	2010-06-06 08:15:20.000000000 -0400
+++ audiocd.cpp	2010-06-06 08:18:01.000000000 -0400
@@ -229,20 +229,21 @@
 	// name associated with the device, which throws the rest of audiocd
 	// for a loop.
 	//
+	QString devname;
 	if ( !(drive->dev) || (COOKED_IOCTL == drive->interface) )
 	{
 		// For ATAPI devices, we have no real choice. Use the
 		// user selected value, even if there is none.
 		//
 		kWarning(7117) << "Found an ATAPI device, assuming it is the one specified by the user.";
-		cd->setDevice( drive->cdda_device_name );
+		devname = drive->cdda_device_name;
 	}
 	else
 	{
 		kDebug(7117) << "Found a SCSI or ATAPICAM device.";
 		if ( strlen(drive->dev->device_path) > 0 )
 		{
-			cd->setDevice( drive->dev->device_path );
+			devname = drive->dev->device_path;
 		}
 		else
 		{
@@ -250,13 +251,14 @@
 			// circumstances, so build a representation from
 			// the unit number and SCSI device name.
 			//
-			QString devname = QString::fromLatin1( "/dev/%1%2" )
+			devname = QString::fromLatin1( "/dev/%1%2" )
 				.arg( drive->dev->given_dev_name )
 				.arg( drive->dev->given_unit_number ) ;
 			kDebug(7117) << "  Using derived name " << devname;
-			cd->setDevice( devname );
 		}
 	}
+	if ( cd->deviceName() != devname )
+		cd->setDevice( devname );
 #else
 #ifdef __GNUC__
 	#warning audiocd ioslave is not going to work for you

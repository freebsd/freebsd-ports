--- audiocd.cpp.orig	2014-10-09 07:07:27 UTC
+++ audiocd.cpp
@@ -228,20 +228,21 @@ static void setDeviceToCd(KCompactDisc *
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
@@ -249,13 +250,14 @@ static void setDeviceToCd(KCompactDisc *
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

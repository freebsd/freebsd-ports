--- qsstv/sound/soundcontrol.cpp.orig	2014-12-06 14:41:00 UTC
+++ qsstv/sound/soundcontrol.cpp
@@ -53,8 +53,8 @@ void soundControl::readSettings()
   txClock=qSettings.value("txclock",BASESAMPLERATE).toDouble();
   if(fabs(1-rxClock/BASESAMPLERATE)>0.002) rxClock=BASESAMPLERATE;
   if(fabs(1-txClock/BASESAMPLERATE)>0.002) txClock=BASESAMPLERATE;
-  inputAudioDeviceIndex=qSettings.value("inputAudioDeviceIndex",0).toInt();
-  outputAudioDeviceIndex=qSettings.value("outputAudioDeviceIndex",0).toInt();
+  inputAudioDevice=qSettings.value("inputAudioDevice",0).toString();
+  outputAudioDevice=qSettings.value("outputAudioDevice",0).toString();
   soundIOPtr->soundRoutingInput=  (soundIO::edataSrc)qSettings.value("soundRoutingInput",  0 ).toInt();
   soundIOPtr->soundRoutingOutput= (soundIO::edataDst)qSettings.value("soundRoutingOutput", 0 ).toInt();
   soundIOPtr->recordingSize= qSettings.value("recordingSize", 100 ).toInt();
@@ -69,8 +69,8 @@ void soundControl::writeSettings()
   qSettings.beginGroup("Sound");
   qSettings.setValue("rxclock",rxClock);
   qSettings.setValue("txclock",txClock);
-  qSettings.setValue("inputAudioDeviceIndex",inputAudioDeviceIndex);
-  qSettings.setValue("outputAudioDeviceIndex",outputAudioDeviceIndex);
+  qSettings.setValue("inputAudioDevice",inputAudioDevice);
+  qSettings.setValue("outputAudioDevice",outputAudioDevice);
   qSettings.setValue ("soundRoutingInput", soundIOPtr->soundRoutingInput );
   qSettings.setValue ("soundRoutingOutput",soundIOPtr->soundRoutingOutput );
   qSettings.setValue ("recordingSize",soundIOPtr->recordingSize );
@@ -82,8 +82,8 @@ void soundControl::setParams()
 {
   setValue(rxClock,ui->inputClockLineEdit,9);
   setValue(txClock,ui->outputClockLineEdit,9);
-  setIndex(inputAudioDeviceIndex,ui->inputPCMNameComboBox);
-  setIndex(outputAudioDeviceIndex,ui->outputPCMNameComboBox);
+  setValue(inputAudioDevice,ui->inputPCMNameComboBox);
+  setValue(outputAudioDevice,ui->outputPCMNameComboBox);
   soundIOPtr->inputAudioDevice=ui->inputPCMNameComboBox->currentText();
   soundIOPtr->outputAudioDevice=ui->outputPCMNameComboBox->currentText();
 
@@ -99,13 +99,13 @@ void soundControl::setParams()
 void soundControl::getParams()
 {
   changed=false;
-  int savedInputIdx=inputAudioDeviceIndex;
-  int savedOutputIdx=outputAudioDeviceIndex;
+  QString savedInput=inputAudioDevice;
+  QString savedOutput=outputAudioDevice;
   getValue(rxClock,ui->inputClockLineEdit);
   getValue(txClock,ui->inputClockLineEdit);
 
-  getIndex(inputAudioDeviceIndex,ui->inputPCMNameComboBox);
-  getIndex(outputAudioDeviceIndex,ui->outputPCMNameComboBox);
+  getValue(inputAudioDevice,ui->inputPCMNameComboBox);
+  getValue(outputAudioDevice,ui->outputPCMNameComboBox);
 
   if (ui->inFromCard->isChecked()) soundIOPtr->soundRoutingInput=soundIO::SNDINCARD;
   else if(ui->inFromFile->isChecked()) soundIOPtr->soundRoutingInput=soundIO::SNDINFILE;
@@ -114,7 +114,7 @@ void soundControl::getParams()
   if (ui->outToCard->isChecked()) soundIOPtr->soundRoutingOutput=soundIO::SNDOUTCARD;
   else soundIOPtr->soundRoutingOutput=soundIO::SNDOUTTOFILE;
   getValue(soundIOPtr->recordingSize,ui->mbSpinBox);
-  if(savedInputIdx!=inputAudioDeviceIndex) changed=true;
-  if(savedOutputIdx!=outputAudioDeviceIndex) changed=true;
+  if(savedInput!=inputAudioDevice) changed=true;
+  if(savedOutput!=outputAudioDevice) changed=true;
 }
 

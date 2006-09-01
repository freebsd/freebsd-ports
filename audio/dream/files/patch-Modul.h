===================================================================
RCS file: /cvsroot/drm/drm/common/util/Modul.h,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- common/util/Modul.h	2005/05/18 07:50:28	1.1
+++ common/util/Modul.h	2005/09/08 16:22:18	1.2
@@ -217,7 +217,7 @@
 
 /* Implementation *************************************************************/
 /******************************************************************************\
-* CModul																	   *
+* CModul                                                                       *
 \******************************************************************************/
 template<class TInput, class TOutput>
 CModul<TInput, TOutput>::CModul()
@@ -302,7 +302,7 @@
 
 
 /******************************************************************************\
-* Transmitter modul (CTransmitterModul)										   *
+* Transmitter modul (CTransmitterModul)                                        *
 \******************************************************************************/
 template<class TInput, class TOutput>
 CTransmitterModul<TInput, TOutput>::CTransmitterModul()
@@ -347,7 +347,7 @@
 	if (OutputBuffer.GetRequestFlag() == TRUE)
 	{
 		/* Check, if enough input data is available */
-		if (InputBuffer.GetFillLevel() < iInputBlockSize)
+		if (InputBuffer.GetFillLevel() < this->iInputBlockSize)
 		{
 			/* Set request flag */
 			InputBuffer.SetRequestFlag(TRUE);
@@ -356,19 +356,20 @@
 		}
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 		/* Copy extended data from vectors */
-		(*pvecOutputData).SetExData((*pvecInputData).GetExData());
+		(*(this->pvecOutputData)).
+			SetExData((*(this->pvecInputData)).GetExData());
 
 		/* Call the underlying processing-routine */
-		ProcessDataInternal(Parameter);
+		this->ProcessDataInternal(Parameter);
 	
 		/* Write processed data from internal memory in transfer-buffer */
-		OutputBuffer.Put(iOutputBlockSize);
+		OutputBuffer.Put(this->iOutputBlockSize);
 
 		/* Data was provided, clear data request */
 		OutputBuffer.SetRequestFlag(FALSE);
@@ -389,7 +390,7 @@
 	if (OutputBuffer.GetRequestFlag() == TRUE)
 	{
 		/* Check, if enough input data is available from all sources */
-		if (InputBuffer.GetFillLevel() < iInputBlockSize)
+		if (InputBuffer.GetFillLevel() < this->iInputBlockSize)
 		{
 			/* Set request flag */
 			InputBuffer.SetRequestFlag(TRUE);
@@ -412,18 +413,18 @@
 		}
 	
 		/* Get vectors from transfer-buffers */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 		pvecInputData2 = InputBuffer2.Get(iInputBlockSize2);
 		pvecInputData3 = InputBuffer3.Get(iInputBlockSize3);
 
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 		/* Call the underlying processing-routine */
-		ProcessDataInternal(Parameter);
+		this->ProcessDataInternal(Parameter);
 	
 		/* Write processed data from internal memory in transfer-buffer */
-		OutputBuffer.Put(iOutputBlockSize);
+		OutputBuffer.Put(this->iOutputBlockSize);
 
 		/* Data was provided, clear data request */
 		OutputBuffer.SetRequestFlag(FALSE);
@@ -440,13 +441,13 @@
 	{
 		/* Read data and write it in the transfer-buffer.
 		   Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 		/* Call the underlying processing-routine */
-		ProcessDataInternal(Parameter);
+		this->ProcessDataInternal(Parameter);
 		
 		/* Write processed data from internal memory in transfer-buffer */
-		OutputBuffer.Put(iOutputBlockSize);
+		OutputBuffer.Put(this->iOutputBlockSize);
 
 		/* Data was provided, clear data request */
 		OutputBuffer.SetRequestFlag(FALSE);
@@ -459,7 +460,7 @@
 {
 	/* OUTPUT-DRIVEN modul implementation in the transmitter */
 	/* Check, if enough input data is available */
-	if (InputBuffer.GetFillLevel() < iInputBlockSize)
+	if (InputBuffer.GetFillLevel() < this->iInputBlockSize)
 	{
 		/* Set request flag */
 		InputBuffer.SetRequestFlag(TRUE);
@@ -468,17 +469,17 @@
 	}
 
 	/* Get vector from transfer-buffer */
-	pvecInputData = InputBuffer.Get(iInputBlockSize);
+	this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 
 	/* Call the underlying processing-routine */
-	ProcessDataInternal(Parameter);
+	this->ProcessDataInternal(Parameter);
 
 	return TRUE;
 }
 
 
 /******************************************************************************\
-* Receiver modul (CReceiverModul)											   *
+* Receiver modul (CReceiverModul)                                              *
 \******************************************************************************/
 template<class TInput, class TOutput>
 CReceiverModul<TInput, TOutput>::CReceiverModul()
@@ -593,7 +594,7 @@
 	}
 
 	/* Special case if input block size is zero */
-	if (iInputBlockSize == 0)
+	if (this->iInputBlockSize == 0)
 	{
 		InputBuffer.Clear();
 
@@ -605,21 +606,22 @@
 	_BOOLEAN bEnoughData = FALSE;
 
 	/* Check if enough data is available in the input buffer for processing */
-	if (InputBuffer.GetFillLevel() >= iInputBlockSize)
+	if (InputBuffer.GetFillLevel() >= this->iInputBlockSize)
 	{
 		bEnoughData = TRUE;
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 	
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 		/* Copy extended data from vectors */
-		(*pvecOutputData).SetExData((*pvecInputData).GetExData());
+		(*(this->pvecOutputData)).
+			SetExData((*(this->pvecInputData)).GetExData());
 
 		/* Call the underlying processing-routine */
-		ProcessDataThreadSave(Parameter);
+		this->ProcessDataThreadSave(Parameter);
 	
 		/* Reset output-buffers if flag was set by processing routine */
 		if (bResetBuf == TRUE)
@@ -631,7 +633,7 @@
 		else
 		{
 			/* Write processed data from internal memory in transfer-buffer */
-			OutputBuffer.Put(iOutputBlockSize);
+			OutputBuffer.Put(this->iOutputBlockSize);
 		}
 	}
 
@@ -662,19 +664,19 @@
 
 	/* INPUT-DRIVEN modul implementation in the receiver -------------------- */
 	/* Check if enough data is available in the input buffer for processing */
-	if (InputBuffer.GetFillLevel() >= iInputBlockSize)
+	if (InputBuffer.GetFillLevel() >= this->iInputBlockSize)
 	{
 		bEnoughData = TRUE;
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 	
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 		pvecOutputData2 = OutputBuffer2.QueryWriteBuffer();
 		
 		/* Call the underlying processing-routine */
-		ProcessDataThreadSave(Parameter);
+		this->ProcessDataThreadSave(Parameter);
 	
 		/* Reset output-buffers if flag was set by processing routine */
 		if (bResetBuf == TRUE)
@@ -686,7 +688,7 @@
 		else
 		{
 			/* Write processed data from internal memory in transfer-buffer */
-			OutputBuffer.Put(iOutputBlockSize);
+			OutputBuffer.Put(this->iOutputBlockSize);
 		}
 
 		if (bResetBuf2 == TRUE)
@@ -730,20 +732,20 @@
 
 	/* INPUT-DRIVEN modul implementation in the receiver -------------------- */
 	/* Check if enough data is available in the input buffer for processing */
-	if (InputBuffer.GetFillLevel() >= iInputBlockSize)
+	if (InputBuffer.GetFillLevel() >= this->iInputBlockSize)
 	{
 		bEnoughData = TRUE;
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 	
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 		pvecOutputData2 = OutputBuffer2.QueryWriteBuffer();
 		pvecOutputData3 = OutputBuffer3.QueryWriteBuffer();
 		
 		/* Call the underlying processing-routine */
-		ProcessDataThreadSave(Parameter);
+		this->ProcessDataThreadSave(Parameter);
 	
 		/* Reset output-buffers if flag was set by processing routine */
 		if (bResetBuf == TRUE)
@@ -755,7 +757,7 @@
 		else
 		{
 			/* Write processed data from internal memory in transfer-buffer */
-			OutputBuffer.Put(iOutputBlockSize);
+			OutputBuffer.Put(this->iOutputBlockSize);
 		}
 
 		if (bResetBuf2 == TRUE)
@@ -805,10 +807,10 @@
 
 	/* INPUT-DRIVEN modul implementation in the receiver -------------------- */
 	/* Query vector from output transfer-buffer for writing */
-	pvecOutputData = OutputBuffer.QueryWriteBuffer();
+	this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 	/* Call the underlying processing-routine */
-	ProcessDataThreadSave(Parameter);
+	this->ProcessDataThreadSave(Parameter);
 
 	/* Reset output-buffers if flag was set by processing routine */
 	if (bResetBuf == TRUE)
@@ -820,7 +822,7 @@
 	else
 	{
 		/* Write processed data from internal memory in transfer-buffer */
-		OutputBuffer.Put(iOutputBlockSize);
+		OutputBuffer.Put(this->iOutputBlockSize);
 	}
 }
 
@@ -842,7 +844,7 @@
 	}
 
 	/* Special case if input block size is zero and buffer, too */
-	if ((InputBuffer.GetFillLevel() == 0) && (iInputBlockSize == 0))
+	if ((InputBuffer.GetFillLevel() == 0) && (this->iInputBlockSize == 0))
 	{
 		InputBuffer.Clear();
 		return FALSE;
@@ -853,15 +855,15 @@
 	_BOOLEAN bEnoughData = FALSE;
 
 	/* Check if enough data is available in the input buffer for processing */
-	if (InputBuffer.GetFillLevel() >= iInputBlockSize)
+	if (InputBuffer.GetFillLevel() >= this->iInputBlockSize)
 	{
 		bEnoughData = TRUE;
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 	
 		/* Call the underlying processing-routine */
-		ProcessDataThreadSave(Parameter);
+		this->ProcessDataThreadSave(Parameter);
 	}
 
 	return bEnoughData;
@@ -869,7 +871,7 @@
 
 
 /******************************************************************************\
-* Simulation modul (CSimulationModul)										   *
+* Simulation modul (CSimulationModul)                                          *
 \******************************************************************************/
 template<class TInput, class TOutput, class TInOut2>
 CSimulationModul<TInput, TOutput, TInOut2>::CSimulationModul()
@@ -929,7 +931,7 @@
 {
 	/* TransferData needed for simulation */
 	/* Check, if enough input data is available */
-	if (InputBuffer.GetFillLevel() < iInputBlockSize)
+	if (InputBuffer.GetFillLevel() < this->iInputBlockSize)
 	{
 		/* Set request flag */
 		InputBuffer.SetRequestFlag(TRUE);
@@ -938,16 +940,16 @@
 	}
 
 	/* Get vector from transfer-buffer */
-	pvecInputData = InputBuffer.Get(iInputBlockSize);
+	this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 
 	/* Query vector from output transfer-buffer for writing */
-	pvecOutputData = OutputBuffer.QueryWriteBuffer();
+	this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 	/* Call the underlying processing-routine */
-	ProcessDataInternal(Parameter);
+	this->ProcessDataInternal(Parameter);
 
 	/* Write processed data from internal memory in transfer-buffer */
-	OutputBuffer.Put(iOutputBlockSize);
+	OutputBuffer.Put(this->iOutputBlockSize);
 }
 
 template<class TInput, class TOutput, class TInOut2>
@@ -961,26 +963,27 @@
 	_BOOLEAN bEnoughData = FALSE;
 
 	/* Check if enough data is available in the input buffer for processing */
-	if ((InputBuffer.GetFillLevel() >= iInputBlockSize) &&
+	if ((InputBuffer.GetFillLevel() >= this->iInputBlockSize) &&
 		(InputBuffer2.GetFillLevel() >= iInputBlockSize2))
 	{
 		bEnoughData = TRUE;
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 		pvecInputData2 = InputBuffer2.Get(iInputBlockSize2);
 
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 
 		/* Copy extended data from FIRST input vector (definition!) */
-		(*pvecOutputData).SetExData((*pvecInputData).GetExData());
+		(*(this->pvecOutputData)).
+			SetExData((*(this->pvecInputData)).GetExData());
 
 		/* Call the underlying processing-routine */
-		ProcessDataInternal(Parameter);
+		this->ProcessDataInternal(Parameter);
 
 		/* Write processed data from internal memory in transfer-buffer */
-		OutputBuffer.Put(iOutputBlockSize);
+		OutputBuffer.Put(this->iOutputBlockSize);
 	}
 
 	return bEnoughData;
@@ -997,22 +1000,22 @@
 	_BOOLEAN bEnoughData = FALSE;
 
 	/* Check if enough data is available in the input buffer for processing */
-	if (InputBuffer.GetFillLevel() >= iInputBlockSize)
+	if (InputBuffer.GetFillLevel() >= this->iInputBlockSize)
 	{
 		bEnoughData = TRUE;
 
 		/* Get vector from transfer-buffer */
-		pvecInputData = InputBuffer.Get(iInputBlockSize);
+		this->pvecInputData = InputBuffer.Get(this->iInputBlockSize);
 	
 		/* Query vector from output transfer-buffer for writing */
-		pvecOutputData = OutputBuffer.QueryWriteBuffer();
+		this->pvecOutputData = OutputBuffer.QueryWriteBuffer();
 		pvecOutputData2 = OutputBuffer2.QueryWriteBuffer();
 
 		/* Call the underlying processing-routine */
-		ProcessDataInternal(Parameter);
+		this->ProcessDataInternal(Parameter);
 
 		/* Write processed data from internal memory in transfer-buffers */
-		OutputBuffer.Put(iOutputBlockSize);
+		OutputBuffer.Put(this->iOutputBlockSize);
 		OutputBuffer2.Put(iOutputBlockSize2);
 	}
 

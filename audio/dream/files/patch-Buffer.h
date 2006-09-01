===================================================================
RCS file: /cvsroot/drm/drm/common/util/Buffer.h,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- common/util/Buffer.h	2005/05/18 07:50:28	1.1
+++ common/util/Buffer.h	2005/09/08 16:22:18	1.2
@@ -71,7 +71,7 @@
 
 	virtual void				Init(const int iNewBufferSize);
 	virtual CVectorEx<TData>*	Get(const int iRequestedSize);
-	virtual CVectorEx<TData>*	QueryWriteBuffer() {return &vecBuffer;}
+	virtual CVectorEx<TData>*	QueryWriteBuffer() {return &(this->vecBuffer);}
 	virtual void				Put(const int iOfferedSize);
 	virtual void				Clear() {iFillLevel = 0;}
 	virtual int					GetFillLevel() const {return iFillLevel;}
@@ -123,7 +123,7 @@
 template<class TData> void CSingleBuffer<TData>::Init(const int iNewBufferSize)
 {
 	/* Only initialize buffer when size has changed, otherwise preserve data */
-	if (iNewBufferSize != iBufferSize)
+	if (iNewBufferSize != this->iBufferSize)
 	{
 		CBuffer<TData>::Init(iNewBufferSize);
 
@@ -146,7 +146,7 @@
 	/* Block is read, buffer is now empty again */
 	iFillLevel -= iRequestedSize;
 
-	return &vecBuffer;		
+	return &(this->vecBuffer);		
 }
 
 template<class TData> void CSingleBuffer<TData>::Put(const int iOfferedSize)
@@ -170,7 +170,7 @@
 template<class TData> void CCyclicBuffer<TData>::Init(const int iNewBufferSize)
 {
 	/* Only initialize buffer when size has changed, otherwise preserve data */
-	if (iNewBufferSize != iBufferSize)
+	if (iNewBufferSize != this->iBufferSize)
 	{
 		CBuffer<TData>::Init(iNewBufferSize);
 
@@ -191,7 +191,7 @@
 	iPut = 0;
 	iGet = 0;
 	iBufferState = BS_EMPTY;
-	bRequestFlag = FALSE;
+	this->bRequestFlag = FALSE;
 }
 
 template<class TData> CVectorEx<TData>* CCyclicBuffer<TData>::Get(const int iRequestedSize)
@@ -204,7 +204,7 @@
 	iAvailSpace = iPut - iGet;
 	/* Test if wrap is needed */
 	if ((iAvailSpace < 0) || ((iAvailSpace == 0) && (iBufferState == BS_FULL)))
-		iAvailSpace += iBufferSize;
+		iAvailSpace += this->iBufferSize;
 
 #ifdef _DEBUG_
 	if (iAvailSpace < iRequestedSize)
@@ -219,17 +219,17 @@
 	iElementCount = 0;
 
 	/* Test if data can be read in one block */
-	if (iBufferSize - iGet < iRequestedSize)
+	if (this->iBufferSize - iGet < iRequestedSize)
 	{
 		/* Data must be read in two portions */
-		for (i = iGet; i < iBufferSize; i++)
+		for (i = iGet; i < this->iBufferSize; i++)
 		{
-			vecInOutBuffer[iElementCount] = vecBuffer[i];
+			vecInOutBuffer[iElementCount] = this->vecBuffer[i];
 			iElementCount++;
 		}
-		for (i = 0; i < iRequestedSize - iBufferSize + iGet; i++)
+		for (i = 0; i < iRequestedSize - this->iBufferSize + iGet; i++)
 		{
-			vecInOutBuffer[iElementCount] = vecBuffer[i];
+			vecInOutBuffer[iElementCount] = this->vecBuffer[i];
 			iElementCount++;
 		}
 	}
@@ -238,15 +238,15 @@
 		/* Data can be read in one block */
 		for (i = iGet; i < iGet + iRequestedSize; i++)
 		{
-			vecInOutBuffer[iElementCount] = vecBuffer[i];
+			vecInOutBuffer[iElementCount] = this->vecBuffer[i];
 			iElementCount++;
 		}
 	}
 
 	/* Adjust iGet pointer */
 	iGet += iRequestedSize;
-	if (iGet >= iBufferSize)
-		iGet -= iBufferSize;
+	if (iGet >= this->iBufferSize)
+		iGet -= this->iBufferSize;
 
 	/* Test if buffer is empty. If yes, set empty-flag */
 	if ((iGet == iPut) && (iRequestedSize > 0))
@@ -265,7 +265,7 @@
 	iAvailSpace = iGet - iPut;
 	/* Test if wrap is needed */
 	if ((iAvailSpace < 0) || ((iAvailSpace == 0) && (iBufferState == BS_EMPTY)))
-		iAvailSpace += iBufferSize;
+		iAvailSpace += this->iBufferSize;
 
 #ifdef _DEBUG_
 	if (iAvailSpace < iOfferedSize)
@@ -280,17 +280,17 @@
 	iElementCount = 0;
 
 	/* Test if data can be written in one block */
-	if (iBufferSize - iPut < iOfferedSize)
+	if (this->iBufferSize - iPut < iOfferedSize)
 	{
 		/* Data must be written in two steps */
-		for (i = iPut; i < iBufferSize; i++)
+		for (i = iPut; i < this->iBufferSize; i++)
 		{
-			vecBuffer[i] = vecInOutBuffer[iElementCount];
+			this->vecBuffer[i] = vecInOutBuffer[iElementCount];
 			iElementCount++;
 		}
-		for (i = 0; i < iOfferedSize - iBufferSize + iPut; i++)
+		for (i = 0; i < iOfferedSize - this->iBufferSize + iPut; i++)
 		{
-			vecBuffer[i] = vecInOutBuffer[iElementCount];
+			this->vecBuffer[i] = vecInOutBuffer[iElementCount];
 			iElementCount++;
 		}
 	}
@@ -299,15 +299,15 @@
 		/* Data can be written in one block */
 		for (i = iPut; i < iPut + iOfferedSize; i++)
 		{
-			vecBuffer[i] = vecInOutBuffer[iElementCount];
+			this->vecBuffer[i] = vecInOutBuffer[iElementCount];
 			iElementCount++;
 		}
 	}
 
 	/* Adjust iPut pointer */
 	iPut += iOfferedSize;
-	if (iPut >= iBufferSize)
-		iPut -= iBufferSize;
+	if (iPut >= this->iBufferSize)
+		iPut -= this->iBufferSize;
 
 	/* Test if buffer is full. If yes, set full-flag */
 	if ((iGet == iPut) && (iOfferedSize > 0))
@@ -322,9 +322,9 @@
 	   Take into account the flag-information (full or empty buffer) */
 	iFillLevel = iPut - iGet;
 	if ((iFillLevel == 0) && (iBufferState == BS_FULL))
-		iFillLevel = iBufferSize;
+		iFillLevel = this->iBufferSize;
 	if (iFillLevel < 0)
-		iFillLevel += iBufferSize;	/* Wrap around */
+		iFillLevel += this->iBufferSize;	/* Wrap around */
 
 	return iFillLevel;
 }

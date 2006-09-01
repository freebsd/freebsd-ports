===================================================================
RCS file: /cvsroot/drm/drm/common/util/Vector.h,v
retrieving revision 1.2
retrieving revision 1.3
diff -u -r1.2 -r1.3
--- common/util/Vector.h	2005/06/29 21:21:25	1.2
+++ common/util/Vector.h	2005/09/08 16:22:18	1.3
@@ -39,7 +39,7 @@
 template<class TData> class CVector : public vector<TData>
 {
 public:
-	CVector() : pData(begin()), iBitArrayCounter(0), iVectorSize(0) {}
+	CVector() : iBitArrayCounter(0), iVectorSize(0) {pData = this->begin();}
 	CVector(const int iNeSi) {Init(iNeSi);}
 	CVector(const int iNeSi, const TData tInVa) {Init(iNeSi, tInVa);}
 	virtual	~CVector() {}
@@ -49,8 +49,8 @@
 	   pointer must be set to the new data source. The bit access is, by
 	   default, reset */
 	CVector(const CVector<TData>& vecI) :
-		vector<TData>(static_cast<const vector<TData>&>(vecI)), 
-		iVectorSize(vecI.Size()), pData(begin()), iBitArrayCounter(0) {}
+		vector<TData>(static_cast<const vector<TData>&>(vecI)),
+		iVectorSize(vecI.Size()), iBitArrayCounter(0) {pData = this->begin();}
 
 	virtual void Init(const int iNewSize);
 
@@ -87,7 +87,7 @@
 
 	inline CVector<TData>& operator=(const CVector<TData>& vecI) {
 #ifdef _DEBUG_
-		/* Vectors which shall be copied MUST have same size! (If this is 
+		/* Vectors which shall be copied MUST have same size! (If this is
 		   satisfied, the parameter "iVectorSize" must not be adjusted as
 		   a side effect) */
 		if (vecI.Size() != iVectorSize)
@@ -100,7 +100,7 @@
 
 		/* Reset my data pointer in case, the operator=() of the base class
 		   did change the actual memory */
-	  	pData = begin();
+		pData = this->begin();
 
 		return *this;
 	}
@@ -125,9 +125,9 @@
 
 	/* Clear old buffer and reserve memory for new buffer, get iterator
 	   for pointer operations */
-	clear();
-	resize(iNewSize);
-	pData = begin();
+	this->clear();
+	this->resize(iNewSize);
+	pData = this->begin();
 }
 
 template<class TData> void CVector<TData>::Init(const int iNewSize, 
@@ -143,11 +143,11 @@
 template<class TData> void CVector<TData>::Enlarge(const int iAddedSize)
 {
 	iVectorSize += iAddedSize;
-	resize(iVectorSize);
+	this->resize(iVectorSize);
 
 	/* We have to reset the pointer since it could be that the vector size was
 	   zero before enlarging the vector */
-	pData = begin();
+	pData = this->begin();
 }
 
 template<class TData> void CVector<TData>::Reset(const TData tResetVal)
@@ -224,21 +224,21 @@
 template<class TData> void CShiftRegister<TData>::AddBegin(const TData tNewD)
 {
 	/* Shift old values */
-	for (int i = iVectorSize - 1; i > 0; i--)
-		pData[i] = pData[i - 1];
+	for (int i = this->iVectorSize - 1; i > 0; i--)
+		this->pData[i] = this->pData[i - 1];
 
 	/* Add new value */
-	pData[0] = tNewD;
+	this->pData[0] = tNewD;
 }
 
 template<class TData> void CShiftRegister<TData>::AddEnd(const TData tNewD)
 {
 	/* Shift old values */
-	for (int i = 0; i < iVectorSize - 1; i++)
-		pData[i] = pData[i + 1];
+	for (int i = 0; i < this->iVectorSize - 1; i++)
+		this->pData[i] = this->pData[i + 1];
 
 	/* Add new value */
-	pData[iVectorSize - 1] = tNewD;
+	this->pData[this->iVectorSize - 1] = tNewD;
 }
 
 template<class TData> void CShiftRegister<TData>::AddEnd(const CVector<TData>& vectNewD,
@@ -246,16 +246,16 @@
 {
 	int i, iBlockEnd, iMovLen;
 
-	iBlockEnd = iVectorSize - iLen;
+	iBlockEnd = this->iVectorSize - iLen;
 	iMovLen = iLen;
 
 	/* Shift old values */
 	for (i = 0; i < iBlockEnd; i++)
-		pData[i] = pData[iMovLen++];
+		this->pData[i] = this->pData[iMovLen++];
 
 	/* Add new block of data */
 	for (i = 0; i < iLen; i++)
-		pData[iBlockEnd++] = vectNewD[i];
+		this->pData[iBlockEnd++] = vectNewD[i];
 }
 
 
@@ -271,7 +271,7 @@
 		CVector<TData>(iNeSi, tInVa), iCurIdx(0) {}
 
 	void Add(const TData tNewD);
-	inline TData Get() {return pData[iCurIdx];}
+	inline TData Get() {return this->pData[iCurIdx];}
 
 	virtual void Init(const int iNewSize);
 	virtual void Init(const int iNewSize, const TData tIniVal);
@@ -295,11 +295,11 @@
 
 template<class TData> void CFIFO<TData>::Add(const TData tNewD)
 {
-	pData[iCurIdx] = tNewD;
+	this->pData[iCurIdx] = tNewD;
 
 	/* Increment index */
 	iCurIdx++;
-	if (iCurIdx >= iVectorSize)
+	if (iCurIdx >= this->iVectorSize)
 		iCurIdx = 0;
 }
 
@@ -334,7 +334,7 @@
 
 	/* Init each vector in vector */
 	for (int i = 0; i < iNewSize; i++)
-		pData[i].Init(iNewVecSize, 0);
+		this->pData[i].Init(iNewVecSize, 0);
 
 	/* Init current average result */
 	tCurAvResult.Init(iNewVecSize, 0);
@@ -355,15 +355,15 @@
 	history buffer
 */
 	/* Subtract oldest value */
-	tCurAvResult -= pData[iCurIdx];
+	tCurAvResult -= this->pData[iCurIdx];
 
 	/* Add new value and write in memory */
 	tCurAvResult += tNewD;
-	pData[iCurIdx] = tNewD;
+	this->pData[iCurIdx] = tNewD;
 
 	/* Increase position pointer and test if wrap */
 	iCurIdx++;
-	if (iCurIdx >= iVectorSize)
+	if (iCurIdx >= this->iVectorSize)
 		iCurIdx = 0;
 }
 
@@ -381,7 +381,7 @@
 	/* This flag indicates that the symbol ID has changed */
 	_BOOLEAN	bSymbolIDHasChanged;
 
-	/* The channel estimation needs information about timing corrections, 
+	/* The channel estimation needs information about timing corrections,
 	   because it is using information from the symbol memory */
 	int			iCurTimeCorr;
 };

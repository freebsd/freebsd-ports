--- src/utils/Contexts/ContextBase.h.orig	2019-03-25 18:03:45 UTC
+++ src/utils/Contexts/ContextBase.h
@@ -44,7 +44,7 @@ public:
 	FileRecordMgr *getFile(int fileIdx) { return _files[fileIdx]; }
 	void setProgram(PROGRAM_TYPE program) { _program = program; }
 
-	void addInputFile(const string &inputFile) { _fileNames.push_back(inputFile); }
+	void addInputFile(const string &inputFile) { _fileNames.push_back(inputFile); cerr << "Adding " << inputFile << endl; }
 
 	int getNumInputFiles() const { return _fileNames.size(); }
 	const string &getInputFileName(int fileNum) const { return _fileNames[fileNum]; }

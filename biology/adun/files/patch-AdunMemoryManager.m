--- Kernel/AdunKernel/Framework/AdunMemoryManager.m.orig	Tue Jun 13 12:16:44 2006
+++ Kernel/AdunKernel/Framework/AdunMemoryManager.m	Sun Nov  5 13:15:25 2006
@@ -68,6 +68,7 @@
 	NSError* error;
 	NSMutableDictionary* errorDict;
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -77,6 +78,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	//The return value of malloc(0) is implementation dependant
 	//It can return NULL in which case it is indistinguisable from
@@ -133,6 +135,7 @@
 	
 	memset(array, 0, size);
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -143,6 +146,7 @@
 			mem_struct.fordblks); 
 		fflush(stderr);
 	}
+#endif
 
 
 	return array;
@@ -154,6 +158,7 @@
 	double *array;
 	AdMatrix *matrix;
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -163,6 +168,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	matrix = (AdMatrix*)malloc(sizeof(AdMatrix));
 	matrix->no_rows = no_rows;
@@ -172,6 +178,7 @@
 	for(i=0, j=0; i < no_rows; i++, j = j + no_columns)
 			matrix->matrix[i] = array + j;
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -181,6 +188,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON,
 		 	mem_struct.fordblks); 
 	}
+#endif
 
 	return matrix;
 }
@@ -191,6 +199,7 @@
 	int *array;
 	IntMatrix *matrix;
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -200,6 +209,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	matrix = (IntMatrix*)malloc(sizeof(IntMatrix));
 	matrix->no_rows = no_rows;
@@ -209,6 +219,7 @@
 	for(i=0, j=0; i < no_rows; i++, j = j + no_columns)
 			matrix->matrix[i] = array + j;
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -220,6 +231,7 @@
 	}
 
 	return matrix;
+#endif
 }
 
 - (InterTable*) allocateInterTableWithRows: (int) no_rows withColumns: (int) no_columns
@@ -228,6 +240,7 @@
 	double *array;
 	InterTable *table;
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -237,6 +250,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON,
 			 mem_struct.fordblks); 
 	}
+#endif
 
 	table = (InterTable*)malloc(sizeof(InterTable));
 	table->no_interactions = no_rows;
@@ -248,6 +262,7 @@
 	for(i=0, j=0; i < no_rows; i++, j = j + no_columns)
 			table->table[i] = array + j;
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -257,12 +272,14 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	return table;
 }
 
 - (void) freeArray: (void*)array
 {	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -272,9 +289,11 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	free(array);
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -284,6 +303,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 }
 
 /** Do not use this method to free matrices not allocated by one of the
@@ -297,6 +317,7 @@
 	free(matrix[0]); 	//frees the number array	
 	free(matrix);		//frees the index array	
 
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -306,6 +327,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 }
 
@@ -313,6 +335,7 @@
 {
 	//matrices are allocated as arrays
 	//with another array of indexes
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -322,6 +345,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	if(matrix->no_rows != 0)
 	{
@@ -330,6 +354,7 @@
 	}
 	free(matrix);
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -339,10 +364,12 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 }
 
 - (void) freeIntMatrix: (IntMatrix*) matrix 
 {
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -352,6 +379,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	if(matrix->no_rows != 0)
 	{
@@ -360,6 +388,7 @@
 	}
 	free(matrix);
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -369,6 +398,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 }
 
 - (void) freeInterTable: (InterTable*) matrix  
@@ -376,6 +406,7 @@
 	//matrices are allocated as arrays
 	//with another array of indexes
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -385,6 +416,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 
 	if(matrix->no_interactions != 0)
 	{
@@ -394,6 +426,7 @@
 
 	free(matrix);
 	
+#ifndef __FreeBSD__
 	if(MEMORY_STATS==YES)
 	{
 		mem_struct = mallinfo();
@@ -403,6 +436,7 @@
 			(float)mem_struct.uordblks/(float)MEM_CON, 
 			mem_struct.fordblks); 
 	}
+#endif
 }
 
 @end

--- class/LKV/Str.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/Str.cc	20 Feb 2006 11:11:54 -0000
@@ -331,8 +331,9 @@
 	}
 }
 
-Str Str::next_word(void) return res {
+Str Str::next_word(void) {
 	
+	Str res;
 	char c;
 	unsigned long i;
 	unsigned long j;
@@ -379,8 +380,9 @@
 	return res;
 }
 
-Str Str::next_line(void) return res {
+Str Str::next_line(void) {
 	
+	Str res;
 	unsigned long i = index(0x0a);
 	
 	if (i == (unsigned long)~0) {
@@ -397,15 +399,18 @@
 	}
 	
 	len -= i+1;
+	return res;
 }
 
-Str Str::operator+(const Str & rv) const return res(len+rv.len) {
+Str Str::operator+(const Str & rv) const {
+	Str res(len+rv.len);
 	if (len) bcopy(adr, res.adr, len);
 	if (rv.len) bcopy(rv.adr, res.adr+len, rv.len);
 	return res;
 }
 
-Str Str::operator+(char rv) const return res(len+1) {
+Str Str::operator+(char rv) const {
+	Str res(len+1);
 	if (len) bcopy(adr, res.adr, len);
 	*(res.adr+len) = rv;
 	return res;
@@ -481,6 +486,26 @@
 	return -1;
 }
 
+int Str::operator<(const char * p) const {
+
+	const char * a = adr;
+	unsigned long cnt = 0;
+
+	for (;;) {
+		char c = *p++;
+		if (len == cnt) {
+			if (c == 0)
+				return 0;
+			return -1;
+		}
+		if (c == 0)
+			return 0;
+		if (c != *a)
+			return (*a < c);
+		a++; cnt++;
+	}
+}
+
 int Str::operator<(const Str & rv) const {
 	
 	unsigned long p = (rv.len < len)? rv.len : len;
@@ -726,7 +751,9 @@
 }
 
 
-Str LtoStr(long num) return res(4) {
+Str LtoStr(long num) {
+	
+	Str res(4);
 	
 	// if (res.fail) return Str();
 	
@@ -744,10 +771,12 @@
 	return Str(lv)+rv;
 }
 
-Str FtoStr(double val) return res; {
+Str FtoStr(double val) {
+	Str res;
 	static char buf[40];
 	sprintf(buf,"%1.*g",DBL_DIG,val);
 	res = Str(buf);
+	return res;
 }
 
 void Str::implode_escape_sequences(void) {

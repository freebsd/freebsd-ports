https://github.com/BenLangmead/bowtie2/issues/81

--- aligner_result.cpp.orig	2016-12-30 15:40:06 UTC
+++ aligner_result.cpp
@@ -1130,7 +1130,7 @@ bool AlnFlags::printYF(BTString& o, bool
 	else if(!nfilt_  ) flag = "NS";
 	else if(!scfilt_ ) flag = "SC";
 	else if(!qcfilt_ ) flag = "QC";
-	if(flag > 0) {
+	if(*flag != '\0') {
 		if(!first) o.append('\t');
 		o.append("YF:Z:");
 		o.append(flag);

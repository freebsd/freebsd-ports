--- sv.c
+++ sv.c
@@ -10421,7 +10421,8 @@ Perl_sv_dup(pTHX_ const SV *sstr, CLONE_PARAMS* param)
 		IoBOTTOM_NAME(dstr)	= SAVEPV(IoBOTTOM_NAME(dstr));
 		break;
 	    case SVt_PVAV:
-		if (AvARRAY((AV*)sstr)) {
+		/* avoid cloning an empty array */
+		if (AvARRAY((AV *)sstr) && AvFILLp((AV *)sstr) >= 0) {
 		    SV **dst_ary, **src_ary;
 		    SSize_t items = AvFILLp((AV*)sstr) + 1;
 
@@ -10446,6 +10447,8 @@ Perl_sv_dup(pTHX_ const SV *sstr, CLONE_PARAMS* param)
 		else {
 		    AvARRAY((AV*)dstr)	= NULL;
 		    AvALLOC((AV*)dstr)	= (SV**)NULL;
+		    AvMAX(  (AV *)dstr)	= -1;
+		    AvFILLp((AV *)dstr)	= -1;
 		}
 		break;
 	    case SVt_PVHV:

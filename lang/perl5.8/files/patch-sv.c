--- sv.c
+++ sv.c
@@ -9813,7 +9813,8 @@ Perl_sv_dup(pTHX_ SV *sstr, CLONE_PARAMS* param)
 		IoBOTTOM_NAME(dstr)	= SAVEPV(IoBOTTOM_NAME(dstr));
 		break;
 	    case SVt_PVAV:
-		if (AvARRAY((AV*)sstr)) {
+		/* avoid cloning an empty array */
+		if (AvARRAY((AV*)sstr) && AvFILLp((AV*)sstr) >= 0) {
 		    SV **dst_ary, **src_ary;
 		    SSize_t items = AvFILLp((AV*)sstr) + 1;
 
@@ -9838,6 +9839,8 @@ Perl_sv_dup(pTHX_ SV *sstr, CLONE_PARAMS* param)
 		else {
 		    SvPV_set(dstr, NULL);
 		    AvALLOC((AV*)dstr)	= (SV**)NULL;
+		    AvMAX(  (AV *)dstr)	= -1;
+		    AvFILLp((AV *)dstr)	= -1;
 		}
 		AvARYLEN((AV*)dstr) = sv_dup_inc(AvARYLEN((AV*)sstr), param);
 		break;

--- KasumiDic.cxx.orig	2007-10-30 15:09:23 UTC
+++ KasumiDic.cxx
@@ -75,7 +75,6 @@ void KasumiDic::load(KasumiConfiguration *conf)
   const int FREQ_UBOUND = conf->getPropertyValueByInt("MaxFrequency");
 
   int anthy_version = atoi(anthy_get_version_string());
-  assert(anthy_version != 0);
 
   try{
       if(anthy_priv_dic_select_first_entry() == -1){

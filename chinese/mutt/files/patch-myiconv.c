--- myiconv.c.orig	2016-12-02 11:18:42.601104000 +0800
+++ myiconv.c	2016-12-02 11:18:42.601603000 +0800
@@ -0,0 +1,167 @@
+/*
+ * Contributed by Kuang-che Wu <kcwu@kcwu.dyndns.org>
+ */
+#if HAVE_CONFIG_H
+# include "config.h"
+#endif
+
+#include <stdio.h>
+#include <stdlib.h>
+#include "mutt.h"
+#include "charset.h"
+#include <hz.h>
+#include <dlfcn.h>                   
+
+
+
+#ifdef HAVE_ICONV
+
+typedef struct myiconv {
+    iconv_t cd;
+    int incode,outcode;
+    int myjob;
+} myiconv_t;
+
+static int is_init;
+static void *dlh;
+static iconv_t (*old_iconv_open)(const char *tocode, const char *fromcode);
+static size_t (*old_iconv)(iconv_t cd, ICONV_CONST char **inbuf, 
+	size_t *inbytesleft, char **outbuf, size_t *outbytesleft);
+static int (*old_iconv_close) (iconv_t cd);
+static int inst;
+
+static void init(void)
+{
+    hz_setup();
+    dlh=dlopen("libiconv.so",RTLD_LAZY);
+    if(dlh) {
+	old_iconv_open=dlsym(dlh,"iconv_open");
+	old_iconv=dlsym(dlh,"iconv");
+	old_iconv_close=dlsym(dlh,"iconv_close");
+    }
+    is_init=1;
+}
+
+static size_t myconv(ICONV_CONST char **inbuf, 
+	size_t *inbytesleft, char **outbuf, size_t *outbytesleft)
+{
+    /* reference to autogb.c */
+    int count;
+    char buff[MAX_BUFFER*3];
+    char *pbuf,*ps;
+    size_t rt=0;
+
+    pbuf=&buff[2];
+
+    count=*inbytesleft;
+    if(count>MAX_BUFFER) count=MAX_BUFFER;
+    memcpy(pbuf,*inbuf,count);
+    *inbuf+=count;
+    *inbytesleft-=count;
+    while(count>0) {
+	rt+=count;
+	ps=hz_convert(pbuf,&count,0);
+	memcpy(*outbuf,ps,count);
+	*outbuf+=count; *outbytesleft+=count;
+	pbuf=&buff[2];
+
+	count=*inbytesleft;
+	if(count>MAX_BUFFER) count=MAX_BUFFER;
+	memcpy(pbuf,*inbuf,count);
+	*inbuf+=count;
+	*inbytesleft-=count;
+    }
+    return rt;
+}
+
+int conv_str(const char* str_code)
+{
+    int i;
+    char *str;
+    struct mapping {
+	char *code;
+	int value;
+    } map[]={
+	{"gb2312",GB_CODE},
+	{"euccn",GB_CODE},
+	{"big5",BIG5_CODE},
+	{0,OTHER_CODE}, /* should we handle below cases? */
+	{"hz",HZ_CODE},
+	{"uni",UNI_CODE},
+	{"utf7",UTF7_CODE},
+	{"utf8",UTF8_CODE},
+    };
+    str=strdup(str_code);
+    if(strchr(str,'/'))
+	*strchr(str,'/')=0;
+    for(i=0;map[i].code;i++)
+	if(mutt_chscmp(str,map[i].code))
+	    break;
+    free(str);
+    return map[i].value; 
+}
+
+iconv_t iconv_open (const char *tocode, const char *fromcode)
+{
+    myiconv_t *mycd=(myiconv_t*)-1;
+    iconv_t cd;
+    char *_tocode, *_fromcode;
+
+    _tocode = tocode;
+    _fromcode = fromcode;
+
+    if (!mutt_strcmp(tocode,"big5")) _tocode = "big5-hkscs";
+    if (!mutt_strcmp(fromcode,"big5")) _fromcode = "big5-hkscs";
+
+    if(!is_init) init();
+    if(!old_iconv_open) 
+	return (iconv_t)(-1);
+
+    if((cd=old_iconv_open(_tocode,_fromcode))!=(iconv_t)-1) {
+    	mycd=(myiconv_t*)calloc(1,sizeof(myiconv_t));
+	mycd->cd=cd;
+	mycd->incode=conv_str(fromcode);
+	mycd->outcode=conv_str(tocode);
+	/* inst==0 is because:
+	   libhz only has one stack, and 
+	   it will destroy all instance's data when setup stack.
+
+	   If want to fix, libhz's init func should know which inst.
+	 */
+	if(inst==0 && mycd->incode!=mycd->outcode && 
+		hz_search(mycd->incode,mycd->outcode,8)) {
+	    inst++;
+	    mycd->myjob=1;
+	}
+    }
+    return (iconv_t)mycd;
+}
+
+size_t iconv (iconv_t cd, ICONV_CONST char **inbuf, size_t *inbytesleft,
+	      char **outbuf, size_t *outbytesleft)
+{
+    myiconv_t *mycd=(myiconv_t*)cd;
+    size_t rt=(size_t)0;
+    if(mycd->myjob) {
+	if(!inbuf || !*inbuf || !outbuf || !*outbuf)
+	    hz_search(mycd->incode,mycd->outcode,8);
+	else
+	    rt=myconv(inbuf,inbytesleft,outbuf,outbytesleft);
+    } else if(old_iconv)
+	rt=old_iconv(mycd->cd,inbuf,inbytesleft,outbuf,outbytesleft);
+    return rt;
+}
+
+int iconv_close (iconv_t cd)
+{
+    myiconv_t *mycd=(myiconv_t*)cd;
+    if(!old_iconv_close)
+	return 0;
+    old_iconv_close(mycd->cd);
+    if(mycd->myjob)
+	inst--;
+    free(mycd);
+    return 0;
+}
+
+#endif

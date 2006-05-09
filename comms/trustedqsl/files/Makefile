# $FreeBSD$

all:
	(cd tqsllib-2.0;./configure --with-wxwindows=${X11BASE}/bin/wxgtk2-2.6-config;make;make converter;make gen_crq;make load_cert;make station_loc)
	(cd TrustedQSL-1.11;make)

install:
	(cd tqsllib-2.0;make install)
	(cd tqsllib-2.0/.libs; \
	%%INSTALL%% converter gen_crq load_cert station_loc %%PREFIX%%/bin)
	(cd TrustedQSL-1.11;make install)

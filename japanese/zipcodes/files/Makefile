# $FreeBSD$
.SUFFIXES: .csv .euc-csv

CSV=	ken_all.csv
#CSV=	01hokkai.csv 02aomori.csv 03iwate.csv 04miyagi.csv \
#	05akita.csv 06yamaga.csv 07fukush.csv 08ibarak.csv \
#	09tochig.csv 10gumma.csv 11saitam.csv 12chiba.csv \
#	13tokyo.csv 14kanaga.csv 15niigat.csv 16toyama.csv \
#	17ishika.csv 18fukui.csv 19yamana.csv 20nagano.csv \
#	21gifu.csv 22shizuo.csv 23aichi.csv 24mie.csv \
#	25shiga.csv 26kyouto.csv 27osaka.csv 28hyogo.csv \
#	29nara.csv 30wakaya.csv 31tottor.csv 32shiman.csv \
#	33okayam.csv 34hirosh.csv 35yamagu.csv 36tokush.csv \
#	37kagawa.csv 38ehime.csv 39kochi.csv 40fukuok.csv \
#	41saga.csv 42nagasa.csv 43kumamo.csv 44oita.csv \
#	45miyaza.csv 46kagosh.csv 47okinaw.csv
EUCCSV=	${CSV:%.csv=%.euc-csv}
PERL?=	/usr/bin/perl
NKF?=	${LOCALBASE}/bin/nkf
_DESTDIR=${STAGEDIR}${PREFIX}/share/misc/jp-zipcodes

all:	zipcodes.5digits zipcodes.7digits

install: zipcodes.5digits zipcodes.7digits jigyosyo.euc-csv
	mkdir -p ${_DESTDIR}
	for i in zipcodes.5digits zipcodes.7digits; do \
		${INSTALL_DATA} $$i ${_DESTDIR}; \
	done
	${INSTALL_DATA} ken_all.euc-csv ${_DESTDIR}/ken_all-euc.csv
	${INSTALL_DATA} jigyosyo.euc-csv ${_DESTDIR}/jigyosyo-euc.csv

zipcodes.5digits: ${EUCCSV}
	cat ${EUCCSV} | ${PERL} ${SCRIPTDIR}/genold.pl > zipcodes.5digits
zipcodes.7digits: ${EUCCSV}
	cat ${EUCCSV} | ${PERL} ${SCRIPTDIR}/gennew.pl > zipcodes.7digits

.csv.euc-csv:
	${NKF} -X -e < $*.csv > $*.euc-csv

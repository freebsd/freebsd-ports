# New ports collection makefile for:	autoconvert
# Date created:		26 Oct 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autoconvert
PORTVERSION=	0.3.8
CATEGORIES=	chinese
MASTER_SITES=	ftp://banyan.dlut.edu.cn/pub/PEOPLE/saka/ \
		http://www.csie.nctu.edu.tw/~yinjieh/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autob5 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/autogb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libhz.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libhz.so.0.0 ${PREFIX}/lib/libhz.so.0
	cd ${PREFIX}/lib; ${LN} -sf libhz.so.0 libhz.so
	${MKDIR} ${PREFIX}/share/autoconvert
.for i in ChangeLog GPL LICENSE Readme TODO Thanks Version hz.txt procmailrc.example shed.big5 shed.gb shed.uni shed.utf7 shed.utf8
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/autoconvert
.endfor

.for i in hz.h zhstatis.h
	${INSTALL_DATA} ${WRKSRC}/include/$i ${PREFIX}/include
.endfor

.include <bsd.port.mk>

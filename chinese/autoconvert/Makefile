# New ports collection makefile for:	autoconvert
# Date created:		26 Oct 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autoconvert
PORTVERSION=	0.3.5
CATEGORIES=	chinese
MASTER_SITES=	http://www.linuxfocus.org/~yu.guanghui/ \
		ftp://ftp.dlut.edu.cn/pub/PEOPLE/saka/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

WRKSRC=		${WRKDIR}/autoconvert

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autob5 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/autogb ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/autoconvert
.for i in ChangeLog GPL LICENSE Readme TODO Version hz.txt procmailrc.example shed.big5 shed.gb
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/autoconvert
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	zh-chm2html
# Date created:		16 April 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	chm2html
PORTVERSION=	0.1a
CATEGORIES=	chinese
MASTER_SITES=	http://www.geocities.com/labourvanity/pub/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/chm2html/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CHM Tools package

WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
		@cd ${WRKSRC} && ${TAR} zxvf chmtools.tar.gz
		@cd ${WRKSRC} && ${TAR} zxvf utf-converter-1.0.tar.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/chm2html ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/hhc2bookmark.pl ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/hhc2html.pl ${PREFIX}/bin
		${INSTALL_SCRIPT} ${FILESDIR}/chm.sh ${PREFIX}/bin

.include <bsd.port.mk>

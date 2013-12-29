# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	basicdsp
PORTVERSION=	1.01
PORTREVISION=	4
CATEGORIES=	cad hamradio
MASTER_SITES=	http://wwwhome.cs.utwente.nl/~ptdeboer/ham/basicdsp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	A program for experimenting with simple audio DSP algorithms

LICENSE=	GPLv2

USE_DOS2UNIX=	yes
USE_WX=		2.6+
WX_UNICODE=	yes
WX_COMPS=	wx wx:build wx:run

post-patch:
	@${REINPLACE_CMD} -e 's|%%WX_CONFIG%%|${WX_CONFIG}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN}	${WRKSRC}/basicdsp.1 ${STAGEDIR}${MANPREFIX}/man/man1/basicdsp.1
	${INSTALL_PROGRAM}	${WRKSRC}/basicdsp ${STAGEDIR}${PREFIX}/bin/basicdsp

.include <bsd.port.mk>

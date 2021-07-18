# Created by: Diane Bruce <db@db.net>

PORTNAME=	basicdsp
PORTVERSION=	1.01
PORTREVISION=	10
CATEGORIES=	cad education hamradio
MASTER_SITES=	http://wwwhome.cs.utwente.nl/~ptdeboer/ham/basicdsp/ \
		LOCAL/db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Program for experimenting with simple audio DSP algorithms

LICENSE=	GPLv2

USES=		compiler:c++11-lang dos2unix tar:tgz
USE_WX=		2.8+
WX_COMPS=	wx wx:build wx:run

post-patch:
	@${REINPLACE_CMD} -e 's|%%WX_CONFIG%%|${WX_CONFIG}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN}	${WRKSRC}/basicdsp.1 ${STAGEDIR}${MANPREFIX}/man/man1/basicdsp.1
	${INSTALL_PROGRAM}	${WRKSRC}/basicdsp ${STAGEDIR}${PREFIX}/bin/basicdsp

.include <bsd.port.mk>

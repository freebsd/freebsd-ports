# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	qe
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	http://www.cc.ncu.edu.tw/~center5/product/qe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PE2-like editor program for Unix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake ncurses

post-configure:
	@${REINPLACE_CMD} -e '49s,-s,,' ${WRKSRC}/src/Makefile

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/qe
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qe
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/qe

.include <bsd.port.mk>

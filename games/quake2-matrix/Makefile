# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	matrix
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/mods/
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	Matrix-v${PORTVERSION}.fixed.Linux

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Matrix modification for Quake II

BROKEN=		unfetchable

USES=		gmake tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/MatrixFixSource
ALL_TARGET=	release

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake2-data/Makefile.include"

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' \
		${BUILD_WRKSRC}/q_shared.[ch]

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/matrix/game.so \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.cfg *.ini *.pak \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

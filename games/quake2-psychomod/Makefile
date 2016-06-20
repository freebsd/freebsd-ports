# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psychomod
PORTVERSION=	3.1
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Psychomod modification for Quake II

USES=		dos2unix gmake tar:bzip2
DOS2UNIX_GLOB=	*.c *.h
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	release

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake2-data/Makefile.include"

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' \
		${BUILD_WRKSRC}/q_shared.[ch]

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/psychomod/game.so \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.cfg pak0.pak \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

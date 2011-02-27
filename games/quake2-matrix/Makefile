# New ports collection makefile for:	quake2-matrix
# Date created:				2006-12-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	matrix
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/mods/
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	Matrix-v${PORTVERSION}.fixed.Linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Matrix modification for Quake II

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/MatrixFixSource
ALL_TARGET=	release

DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' \
		${BUILD_WRKSRC}/q_shared.[ch]

do-install:
	${MKDIR} ${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/matrix/game.so \
		${Q2DIR}/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.cfg *.ini *.pak ${Q2DIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

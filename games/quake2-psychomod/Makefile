# New ports collection makefile for:	quake2-psychomod
# Date created:				2006-12-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	psychomod
PORTVERSION=	3.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Psychomod modification for Quake II

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	release

DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' \
		${BUILD_WRKSRC}/q_shared.[ch]

do-install:
	${MKDIR} ${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/psychomod/game.so \
		${Q2DIR}/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.cfg pak0.pak ${Q2DIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

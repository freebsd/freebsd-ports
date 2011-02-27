# New ports collection makefile for:	quake2-lights
# Date created:				2006-12-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	lights
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/mods/:data \
		${MASTER_SITE_LOCAL:S|$|:src|}
MASTER_SITE_SUBDIR=	alepulver/:src
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	Lights.v${PORTVERSION}.Linux
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:data,src \
		Lights-Bots${EXTRACT_SUFX}:src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lights modification for Quake II

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}/src
ALL_TARGET=	release

DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${BUILD_WRKSRC}/q_shared.c
	@${REINPLACE_CMD} -e 's/<malloc\.h>/<stdlib.h>/' \
		${BUILD_WRKSRC}/ace/acebot_compress.c

do-install:
	${MKDIR} ${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/lights/game.so \
		${Q2DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lights/pak99.pak ${Q2DIR}/${PORTNAME}
	cd ${WRKSRC}/quake2/lights && \
		${CP} -R autoexec.cfg demos pics sprites ${Q2DIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quake2/lights/Readme. ${DOCSDIR}/readme.txt
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	f1spirit-remake
# Date created:		15 May 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	f1spirit-remake
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
# Original braingames site is really slow
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		http://www.braingames.getput.com/f1spirit/downloads/
DISTNAME=	f1spirit-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of classic F1 Spirit racing game

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_ZIP=	yes
USE_GMAKE=	yes
USE_SDL=	sdl net image mixer sound
USE_GL=		gl glu

WRKSRC=		"${WRKDIR}/F-1 Spirit"
BUILD_WRKSRC=	${WRKSRC}/sources

PORTDOCS=	readme.txt

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e 's|"demos"|"${DATADIR}/demos"|g; s|designs/|${DATADIR}/&|g; \
		s|f1spirit2.cfg|${DATADIR}/&|g; s|graphics/|${DATADIR}/&|g; \
		s|sound/|${DATADIR}/&|g; s|tracks/|${DATADIR}/&|g'

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/f1s ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'demos designs f1spirit2.cfg graphics sound tracks' ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	cultivation
# Date created:		06 Feb 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	cultivation
PORTVERSION=	7
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Cultivation_${PORTVERSION}_UnixSource

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Unique game of conflict and cooperation in a gardening community

LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio \
		glut.4:${PORTSDIR}/graphics/libglut

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/game2
BUILD_WRKSRC=	${WRKSRC}/gameSource
MAKE_ARGS=	CXX=${CXX}

PORTDOCS=	changeLog.txt how_to_play.txt

post-patch:
	@cd ${WRKSRC} && ${CAT} Makefile.GnuLinux Makefile.common \
		../minorGems/build/Makefile.minorGems gameSource/Makefile.all \
		../minorGems/build/Makefile.minorGems_targets > gameSource/Makefile
	@${REINPLACE_CMD} -e 's|font\.tga|${DATADIR}/font.tga|; \
		s|language\.txt|${DATADIR}/language.txt|; \
		s|features\.txt|${DATADIR}/features.txt|' \
	       	${BUILD_WRKSRC}/game.cpp
	@${REINPLACE_CMD} -e 's|"languages"|"${DATADIR}/languages"|' \
		${WRKSRC}/../minorGems/util/TranslationManager.cpp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Cultivation ${PREFIX}/bin
	${MKDIR} ${DATADIR}/languages
	${INSTALL_DATA} ${BUILD_WRKSRC}/font.tga ${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/features.txt ${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/language.txt ${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/languages/* ${DATADIR}/languages

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/documentation/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

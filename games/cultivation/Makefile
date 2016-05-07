# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	cultivation
PORTVERSION=	8
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	Cultivation_${PORTVERSION}_UnixSource

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Unique game of conflict and cooperation in a gardening community

LIB_DEPENDS=	libportaudio.so:audio/portaudio

USES=		gmake
USE_XORG=	x11 xi xext xmu
USE_GL=		glut

WRKSRC=		${WRKDIR}/${DISTNAME}/game2
BUILD_WRKSRC=	${WRKSRC}/gameSource
MAKE_ARGS=	CXX=${CXX}

EXTRA_PATCHES=	${FILESDIR}/portaudio19.patch:-p2

PLIST_FILES=	bin/Cultivation
PORTDATA=	*
PORTDOCS=	changeLog.txt how_to_play.txt

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Cultivation ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/languages
	${INSTALL_DATA} ${BUILD_WRKSRC}/font.tga ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/features.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/language.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/languages/* ${STAGEDIR}${DATADIR}/languages
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/documentation/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

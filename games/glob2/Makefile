# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	glob2
PORTVERSION=	0.9.4.4
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Globulation 2, free and innovative strategy game

LICENSE=	GPLv3

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libspeex.so:${PORTSDIR}/audio/speex \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libfreetype.so:${PORTSDIR}/print/freetype2
# Should work with portaudio v19_20071207
# Can be built with portaudio2 but does not run cleanly
#LIB_DEPENDS+=		libportaudio.so:${PORTSDIR}/audio/portaudio2

USES=		gmake
USE_SDL=	image net sdl ttf
USE_GL=		gl
USE_SCONS=	yes
#SCONS_ARGS+=	--portaudio=true
#SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS=	CXXFLAGS+=" -g -pg" INSTALLDIR="${STAGEDIR}${PREFIX}/share"
CFLAGS+=	-Wno-return-type

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 24x24 32x32 48x48 64x64 128x128

#CFLAGS+=	${PTHREAD_CFLAGS} -I. `pkg-config --cflags portaudio-2.0` -I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS} -I. -I${LOCALBASE}/include
#LINKFLAGS=	${PTHREAD_LIBS} `pkg-config --libs portaudio-2.0` -L${LOCALBASE}/lib
LINKFLAGS=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin|${STAGEDIR}${PREFIX}/bin|' \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|portaudio.h|portaudio2/portaudio.h|' ${WRKSRC}/src/VoiceRecorder.cpp
	@${REINPLACE_CMD} -e 's|^Icon.*|Icon=${PORTNAME}|' \
			${WRKSRC}/data/${PORTNAME}.desktop

.for s in 16 24 32 48 64 128
	@cd ${WRKSRC}/data/icons && \
		${MV} glob2-icon-${s}x${s}.png ${PORTNAME}_${s}x${s}.png
.endfor

manual-regression-test:
# Don't enable these tests on pointyhat, they take too long.
.if defined(MAINTAINER_MODE)
	(cd ${WRKSRC}/src && ./glob2 -test-games)
.else
	(cd ${WRKSRC}/src && ./glob2 -test-games-nox)
.endif

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKSRC}/data/icons/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

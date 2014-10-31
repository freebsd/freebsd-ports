# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	glob2
PORTVERSION=	0.9.4.4
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Globulation 2, free and innovative strategy game

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libspeex.so:${PORTSDIR}/audio/speex \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libfreetype.so:${PORTSDIR}/print/freetype2

OPTIONS_DEFINE=	DOCS PORTAUDIO

USES=		pkgconfig scons
USE_SDL=	image net sdl ttf
USE_GL=		gl glu
MAKE_ARGS=	CCFLAGS="${CFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		LIBPATH="${LIBPATH}" \
		BINDIR="${STAGEDIR}${PREFIX}/bin" \
		INSTALLDIR="${STAGEDIR}${PREFIX}/share" \
		DATADIR="${DATADIR}"
INSTALLS_ICONS=	yes

CFLAGS+=	${PA2_CFLAGS} -I${LOCALBASE}/include -Wno-return-type
LDFLAGS+=	${PA2_LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}
LIBPATH=	${LIBPATH2}${LOCALBASE}/lib

PORTDOCS=	README
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2
PA2_CFLAGS+=	-I${LOCALBASE}/include/portaudio2
PA2_LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2
LIBPATH2=	${LOCALBASE}/lib/portaudio2:
MAKE_ARGS+=	--portaudio=true
.else
MAKE_ARGS+=	--portaudio=false
.endif

pre-configure:
	${REINPLACE_CMD} -e \
		's|"-g"|""|' \
		${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e \
		's|portaudio.h|portaudio2/portaudio.h|' \
		${WRKSRC}/src/VoiceRecorder.cpp
	${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PORTNAME}|' \
		${WRKSRC}/data/${PORTNAME}.desktop
	${REINPLACE_CMD} -e \
		'/(PACKAGE_SOURCE_DIR)/s|^|//|' \
		${WRKSRC}/libgag/src/FileManager.cpp

manual-regression-test:
# Don't enable these tests on pointyhat, they take too long.
.if defined(MAINTAINER_MODE)
	(cd ${WRKSRC}/src && ./glob2 -test-games)
.else
	(cd ${WRKSRC}/src && ./glob2 -test-games-nox)
.endif

post-install:
.for s in 16 24 32 48 64 128
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	(cd ${WRKSRC}/data/icons && ${INSTALL_DATA} glob2-icon-${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/${PORTNAME}.png)
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/glob2

.include <bsd.port.mk>

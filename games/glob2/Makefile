# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	glob2
PORTVERSION=	0.9.4.4
PORTREVISION=	29
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Globulation 2, free and innovative strategy game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libspeex.so:audio/speex \
		libfribidi.so:converters/fribidi \
		libboost_thread.so:devel/boost-libs \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	DOCS PORTAUDIO

USES=		compiler:c++11-lang gl gnome pkgconfig scons:python2 sdl
USE_SDL=	image net sdl ttf
USE_GL=		gl glu
MAKE_ARGS=	CCFLAGS="${CFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		BINDIR="${STAGEDIR}${PREFIX}/bin" \
		INSTALLDIR="${STAGEDIR}${PREFIX}/share" \
		DATADIR="${DATADIR}"
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include -Wno-return-type
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

PORTDOCS=	README
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so:audio/portaudio
MAKE_ARGS+=	--portaudio=true
.else
MAKE_ARGS+=	--portaudio=false
.endif

pre-configure:
	${REINPLACE_CMD} -e \
		's|"-g"|""|' \
		${WRKSRC}/SConstruct
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
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/glob2

.include <bsd.port.mk>

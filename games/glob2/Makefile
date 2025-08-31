PORTNAME=	glob2
PORTVERSION=	0.9.5.0.g20240607
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Globulation 2, real-time strategy game
WWW=		https://globulation2.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libportaudio.so:audio/portaudio \
		libspeex.so:audio/speex \
		libfribidi.so:converters/fribidi \
		libboost_thread.so:devel/boost-libs

USES=		compiler:c++14-lang gl localbase:ldflags pkgconfig scons sdl
USE_SDL=	image2 net2 sdl2 ttf2
USE_GL=		gl glu
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	Globulation2
GH_TAGNAME=	bf277676

PORTSCOUT=	limit:^[0-9]

MAKE_ARGS=	CCFLAGS="${CFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		BINDIR="${STAGEDIR}${PREFIX}/bin" \
		INSTALLDIR="${STAGEDIR}${PREFIX}/share" \
		DATADIR="${DATADIR}" \
		--portaudio=true

post-patch:
	${REINPLACE_CMD} '/addDir(PACKAGE_SOURCE_DIR)/d' \
		${WRKSRC}/libgag/src/FileManager.cpp

post-install:
# workaround broken install: *.txt are required for game to run
	${INSTALL_DATA} ${WRKSRC}/data/*.txt ${STAGEDIR}${DATADIR}/data/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/glob2

.include <bsd.port.mk>

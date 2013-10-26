# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	btanks
PORTVERSION=	0.9.8083
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast 2D tank arcade game with multiplayer and split-screen modes

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis \
		smpeg.1:${PORTSDIR}/multimedia/smpeg

USES=		pkgconfig
USE_BZIP2=	yes
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_LUA=	5.0+
USE_OPENAL=	al
USE_SDL=	image sdl
USE_SCONS=	yes
SCONS_ARGS=	prefix=${PREFIX} resources_dir=${DATADIR}
SCONS_BUILDENV=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS} -fpermissive" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		CPPPATH="${LOCALBASE}/include" LIBPATH="${LOCALBASE}/lib"

MAN6=		${PORTNAME}.6

PORTDOCS=	LICENSE LICENSE.EXCEPTION README-en.txt README-linux.txt \
		donate.url homepage.url project_page.url video.txt

DESKTOP_ENTRIES="Battle Tanks" "${COMMENT}" "" "${PORTNAME}" \
		"Game;ArcadeGame;" false

NO_STAGE=	yes
pre-build:
# Regenerate `sl08.h' after we patch `sl08.py' (as patching the header itself
# would have resulted in a larger diff and gratuitous difference with Debian)
	@cd ${WRKSRC} && python engine/sl08/sl08.py > engine/sl08/sl08.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/release/clunk/libclunk.so \
		${WRKSRC}/build/release/engine/libbtanks_engine.so \
		${WRKSRC}/build/release/mrt/libmrt.so \
		${WRKSRC}/build/release/sdlx/libsdlx.so ${PREFIX}/lib
	${INSTALL_MAN} ${FILESDIR}/${MAN6} ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>

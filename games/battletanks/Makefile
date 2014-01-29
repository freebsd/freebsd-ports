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
LIB_DEPENDS=	libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libsmpeg.so:${PORTSDIR}/multimedia/smpeg

USES=		openal:al pkgconfig
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_LUA=	5.0+
USE_SDL=	image sdl
USE_SCONS=	yes
USE_PYTHON_BUILD=	yes
SCONS_ARGS=	prefix=${PREFIX} resources_dir=${DATADIR} \
		--install-sandbox=${STAGEDIR}
SCONS_BUILDENV=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS} -fpermissive" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		CPPPATH="${LOCALBASE}/include" LIBPATH="${LOCALBASE}/lib"

PORTDOCS=	LICENSE LICENSE.EXCEPTION README-en.txt README-linux.txt \
		donate.url homepage.url project_page.url video.txt

DESKTOP_ENTRIES="Battle Tanks" "" "" "${PORTNAME}" "Game;ArcadeGame;" ""

pre-build:
# Regenerate `sl08.h' after we patch `sl08.py' (as patching the header itself
# would have resulted in a larger diff and gratuitous difference with Debian)
	@cd ${WRKSRC} && ${PYTHON_CMD} engine/sl08/sl08.py > engine/sl08/sl08.h

post-install:
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.6 \
		${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

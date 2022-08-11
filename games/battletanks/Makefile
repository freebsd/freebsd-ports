PORTNAME=	btanks
PORTVERSION=	0.9.8083
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast 2D tank arcade game with multiplayer and split-screen modes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20 \
		libexpat.so:textproc/expat2 \
		libvorbisfile.so:audio/libvorbis \
		libsmpeg.so:multimedia/smpeg

USES=		lua:51 openal:al pkgconfig python:build scons sdl tar:bzip2
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
USE_SDL=	image sdl
MAKE_ARGS=	prefix=${PREFIX} resources_dir=${DATADIR} \
		--install-sandbox=${STAGEDIR}
CXXFLAGS+=	-fpermissive

PORTDOCS=	LICENSE LICENSE.EXCEPTION README-en.txt README-linux.txt \
		donate.url homepage.url project_page.url video.txt

DESKTOP_ENTRIES="Battle Tanks" "" "" "${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/lua5\.1/lua-${LUA_VER}/' \
		${WRKSRC}/engine/SConscript
	@${REINPLACE_CMD} -e "s/env\.has_key('prefix')/'prefix' in env/" \
		${WRKSRC}/mrt/SConscript
# Prevent the clash with /usr/include/semaphore.h
	@${MV} ${WRKSRC}/sdlx/semaphore.h ${WRKSRC}/sdlx/sdlx_semaphore.h
	@${REINPLACE_CMD} -e 's/semaphore\.h"/sdlx_&/' \
		${WRKSRC}/sdlx/semaphore.cpp ${WRKSRC}/sdlx/thread.h

pre-build:
# Regenerate `sl08.h' after we patch `sl08.py' (patching the header itself
# would've resulted in a larger diff and gratuitous difference with Debian)
	cd ${WRKSRC}/engine/sl08 && ${PYTHON_CMD} sl08.py > sl08.h

post-install:
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.6 \
		${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/btanks/*.so

.include <bsd.port.mk>

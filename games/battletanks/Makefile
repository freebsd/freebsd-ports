# New ports collection makefile for:	Battle Tanks
# Date created:				24 Mar 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	btanks
PORTVERSION=	0.9.8083
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast 2D tank arcade game with multiplayer and split-screen modes

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis \
		smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_OPENAL=	al
USE_GCC=	4.3+
USE_LUA=	5.0+
USE_SCONS=	yes
USE_SDL=	image sdl
SCONS_ARGS=	prefix=${PREFIX} resources_dir=${DATADIR}
SCONS_BUILDENV+=CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		CPPPATH="${LOCALBASE}/include" \
		LIBPATH="${LOCALBASE}/lib"

PORTDOCS=	LICENSE LICENSE.EXCEPTION README-en.txt README-linux.txt \
		donate.url homepage.url project_page.url video.txt

DESKTOP_ENTRIES="Battle Tanks" "${COMMENT}" "" "btanks" "Application;Game;" false

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
SCONS_ARGS+=	gcc_visibility=false
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/build/release/clunk/libclunk.so ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/release/engine/libbtanks_engine.so ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/release/mrt/libmrt.so ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/release/sdlx/libsdlx.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	freedroidrpg
PORTVERSION=	0.15.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/freedroid/${SF_NAME}/${SF_NAME}-${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\\1/}/
DISTNAME=	${SF_NAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modification of the classical Freedroid engine into an RPG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	Does not configure on sparc64

GNU_CONFIGURE=	yes
USES=		gmake lua:51
USE_SDL=	sdl image mixer gfx
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
USE_GCC=	any # doesn't build with clang

SF_NAME=	freedroidRPG
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDATA=	*

DESKTOP_ENTRIES="FreedroidRPG" "" \
		"${PORTNAME}" "${SF_NAME}" \
		"Game;RolePlaying;" false

OPTIONS_DEFINE=	BACKTRACE OPENGL VORBIS
OPTIONS_DEFAULT=BACKTRACE OPENGL VORBIS
BACKTRACE_DESC=	Use backtrace() to generate nice bug reports

BACKTRACE_USES=			execinfo
BACKTRACE_CONFIGURE_ENABLE=	backtrace
BACKTRACE_VARS=	STRIP= # empty
OPENGL_USE=			GL=gl
OPENGL_CONFIGURE_ENABLE=	opengl
VORBIS_LIB_DEPENDS=		libvorbis.so:${PORTSDIR}/audio/libvorbis \
				libogg.so:${PORTSDIR}/audio/libogg
VORBIS_CONFIGURE_ENABLE=	vorbis

post-install:
	${INSTALL_DATA} ${WRKSRC}/win32/w32icon2_64x64.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>

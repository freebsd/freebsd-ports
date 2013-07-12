# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	freedroidrpg
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/freedroid/freedroidRPG/freedroidRPG-${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\\1/}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modification of the classical Freedroid engine into an RPG

USE_SDL=	sdl image mixer gfx
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LUA=	5.1+
MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"

MAN6=		freedroidRPG.6

OPTIONS_DEFINE=	BACKTRACE OPENGL VORBIS
BACKTRACE_DESC=	Use backtrace() to generate nice bug reports

OPTIONS_DEFAULT=	BACKTRACE OPENGL VORBIS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBACKTRACE}
LIB_DEPENDS+=	execinfo:${PORTSDIR}/devel/libexecinfo
CONFIGURE_ARGS+=--enable-backtrace
STRIP=		#
.else
CONFIGURE_ARGS+=--disable-backtrace
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
CONFIGURE_ARGS+=--enable-opengl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

.include <bsd.port.mk>

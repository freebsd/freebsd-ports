# New ports collection makefile for:	freedroidrpg
# Date created:			18 Jul 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	freedroidrpg
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/freedroid/freedroidRPG/freedroidRPG-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Modification of the classical Freedroid engine into an RPG

USE_BZIP2=	yes
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	BACKTRACE "Use backtrace() to generate nice bug reports" on \
		OPENGL "Enable the OpenGL support (highly recommended!)" on \
		VORBIS "Enable vorbis support (music)" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_BACKTRACE)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
CONFIGURE_ARGS+=--enable-backtrace
STRIP=		#
.else
CONFIGURE_ARGS+=--disable-backtrace
.endif

.if !defined(WITHOUT_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=--enable-opengl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.7:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.include <bsd.port.mk>

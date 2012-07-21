# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.15
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Cross-platform multimedia development API

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		ac_cv_header_libusbhid_h=no

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-alsa --disable-alsatest
CONFIGURE_ARGS+=--disable-video-directfb

EXAMPLES=	test/*.c test/*.bmp test/*.dat test/*.xbm test/*.wav
DOCS=		BUGS COPYING CREDITS README README-SDL.txt WhatsNew docs.html

OPTIONS_DEFINE=		AALIB ARTS ESOUND GGI NAS OPENGL OSS PULSEAUDIO SVGALIB X11
OPTIONS_DEFAULT=	AALIB OPENGL OSS X11

.if exists(/usr/lib/libvgl.so)
OPTIONS_DEFINE+=	VGL
VGL_DESC=		Video Graphics Lib support
OPTIONS_DEFAULT+=	VGL
.endif

.include <bsd.port.pre.mk>

MAN3!=		${CAT} ${FILESDIR}/man3

.if ${PORT_OPTIONS:MAALIB}
CONFIGURE_ARGS+=	--enable-video-aalib
LIB_DEPENDS+=		aa:${PORTSDIR}/graphics/aalib
.else
CONFIGURE_ARGS+=	--disable-video-aalib
.endif

.if ${PORT_OPTIONS:MARTS}
LIB_DEPENDS+=		artsc:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=		esound
CONFIGURE_ARGS+=	--enable-esd
.else
CONFIGURE_ARGS+=	--disable-esd --disable-esdtest
.endif

.if ${PORT_OPTIONS:MGGI}
LIB_DEPENDS+=		ggi:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=	--enable-video-ggi
.else
CONFIGURE_ARGS+=	--disable-video-ggi
.endif

.if ${PORT_OPTIONS:MNAS}
LIB_DEPENDS+=		audio:${PORTSDIR}/audio/nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if ${PORT_OPTIONS:MOPENGL}
CONFIGURE_ARGS+=	--enable-video-opengl
USE_GL=			yes
.else
CONFIGURE_ARGS+=	--disable-video-opengl
.endif

.if ${PORT_OPTIONS:MOSS}
CONFIGURE_ARGS+=	--enable-oss
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		pulse-simple:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if ${PORT_OPTIONS:MSVGALIB}
LIB_DEPENDS+=		vga:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--enable-video-svga
.else
CONFIGURE_ARGS+=	--disable-video-svga
.endif

.if ${PORT_OPTIONS:MVGL}
CONFIGURE_ARGS+=	--enable-video-vgl
DISPLAY_MSG=		${CAT} ${PKGMESSAGE}
.else
CONFIGURE_ARGS+=	--disable-video-vgl
PKGMESSAGE=		none
DISPLAY_MSG=		${DO_NADA}
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11 xrender xrandr xextproto
.else
PKGNAMESUFFIX=		-nox11
CONFIGURE_ARGS+=	--disable-video-x11
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} &&\
		${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/ &&\
	cd ${WRKSRC} &&\
		${COPYTREE_SHARE} docs ${DOCSDIR}/ "! -regex .*/man3.*"
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} &&\
		${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
.endif
	@${DISPLAY_MSG}

.include <bsd.port.post.mk>

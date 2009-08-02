# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.13
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Cross-platform multimedia development API

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		LDFLAGS="${LDFLAGS}"			\
		ac_cv_header_libusbhid_h=no

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-alsa --disable-alsatest
CONFIGURE_ARGS+=--disable-video-directfb

EXAMPLES=	test/*.c test/*.bmp test/*.dat test/*.xbm test/*.wav
DOCS=		BUGS COPYING CREDITS README README-SDL.txt WhatsNew docs.html

OPTIONS=	AALIB		"ASCII art support"			On  \
		ARTS		"ARts sound system support"		Off \
		ESD		"Enlightenment sound system support"	Off \
		GGI		"General Graphics Interface support"	Off \
		NAS		"Network Audio System support"		Off \
		OPENGL		"OpenGL 2D/3D graphics support"		On  \
		OSS		"Open Sound System support"		On  \
		PULSEAUDIO	"PulseAudio sound system support"       Off \
		SVGALIB		"SVGA graphics support (i386 only)"	Off

.if exists(/usr/lib/libvgl.so)
OPTIONS+=	VGL		"Video Graphics Lib support"		On
.else
WITHOUT_VGL=	true
.endif

.if defined(WITHOUT_X11)
WITHOUT_XLIB=	true
.else
OPTIONS+=	XLIB		"XLib (xorg) graphics support"		On
.endif

.include <bsd.port.pre.mk>

MAN3!=		${CAT} ${FILESDIR}/man3

.if defined(WITHOUT_AALIB)
CONFIGURE_ARGS+=--disable-video-aalib
.else
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-video-aalib
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-arts
.else
CONFIGURE_ARGS+=--disable-arts
.endif

.if defined(WITH_ESD)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.else
CONFIGURE_ARGS+=--disable-esd --disable-esdtest
.endif

.if defined(WITH_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-video-ggi
.else
CONFIGURE_ARGS+=--disable-video-ggi
.endif

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
.else
CONFIGURE_ARGS+=--disable-nas
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--disable-video-opengl
.else
USE_GL=		yes
CONFIGURE_ARGS+=--enable-video-opengl
.endif

.if defined(WITHOUT_OSS)
CONFIGURE_ARGS+=--disable-oss
.else
CONFIGURE_ARGS+=--enable-oss
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse-simple.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--disable-pulseaudio
.endif

.if (defined(WITHOUT_SVGALIB) || ${ARCH} != "i386")
CONFIGURE_ARGS+=--disable-video-svga
.else
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-video-svga
.endif

.if (defined(WITHOUT_VGL) || ${ARCH} != "i386")
CONFIGURE_ARGS+=--disable-video-vgl
PKGMESSAGE=	none
DISPLAY_MSG=	${DO_NADA}
.else
CONFIGURE_ARGS+=--enable-video-vgl
DISPLAY_MSG=	${CAT} ${PKGMESSAGE}
.endif

.if defined(WITHOUT_XLIB)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--disable-video-x11
.else
USE_XORG=	x11 xrender xrandr xextproto
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

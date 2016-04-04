# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.15
PORTREVISION=	7
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Cross-platform multimedia development API

LICENSE=	LGPL21

BUILD_DEPENDS=	nasm:devel/nasm

USES=		gmake iconv libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_libusbhid_h=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-alsa --disable-alsatest \
		--disable-arts --disable-video-directfb --disable-video-ggi

EXAMPLES=	test/*.c test/*.bmp test/*.dat test/*.xbm test/*.wav
DOCS=		BUGS COPYING CREDITS README README-SDL.txt WhatsNew docs.html

OPTIONS_DEFINE=		AALIB DOCS ESOUND EXAMPLES NAS OPENGL OSS \
			PULSEAUDIO SVGALIB X11
OPTIONS_DEFAULT=	AALIB OPENGL OSS X11

.if exists(/usr/lib/libvgl.so)
OPTIONS_DEFINE+=	VGL
VGL_DESC=		Video Graphics Lib support
OPTIONS_DEFAULT+=	VGL
.endif

AALIB_CONFIGURE_ENABLE=		video-aalib
AALIB_LIB_DEPENDS=		libaa.so:graphics/aalib
ESOUND_USE=			GNOME=esound
ESOUND_CONFIGURE_ENABLE=	esd esdtest
NAS_CONFIGURE_ENABLE=		nas
NAS_LIB_DEPENDS=		libaudio.so:audio/nas
OPENGL_CONFIGURE_ENABLE=	video-opengl
OPENGL_USE=			GL=yes
OSS_CONFIGURE_ENABLE=		oss
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio
SVGALIB_CONFIGURE_ENABLE=	video-svga
SVGALIB_LIB_DEPENDS=		libvga.so:graphics/svgalib
VGL_CONFIGURE_ENABLE=		video-vgl
X11_CONFIGURE_ENABLE=		video-x11
X11_USE=			XORG=x11,xrender,xrandr,xextproto

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MVGL}
PKGMESSAGE=		none
.endif

post-patch:
	@${REINPLACE_CMD} -e '/EXTRA_LDFLAGS/s/-liconv/${ICONV_LIB}/' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} &&\
		${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/ &&\
	cd ${WRKSRC} &&\
		${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/ "! -regex .*/man3.*"
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} &&\
		${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>

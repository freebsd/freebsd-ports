# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	snes9x
PORTVERSION=	1.53r81
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://snes9x-gtk.googlecode.com/files/
PKGNAMESUFFIX=	-gtk
DISTNAME=	snes9x-1.53-src

MAINTAINER=	root@cooltrainer.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USE_XORG=	x11 sm ice xext
USES=		gettext gmake perl5 desktop-file-utils pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool libglade2 libxml2
GNU_CONFIGURE=	yes
USE_SDL=	sdl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-alsa

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk

OPTIONS_DEFINE=	DEBUG OPENGL JMA NETPLAY XV XRANDR
OPTIONS_DEFAULT=	JMA NETPLAY XV XRANDR
JMA_DESC=	Enable JMA archive decompression support
NETPLAY_DESC=	Enable network support
XV_DESC=	Enable XVideo output on GTK
XRANDR_DESC=	Enable XRandR support on GTK

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--with-debug
.else
CONFIGURE_ARGS+=	--without-debug
.endif

.if ${PORT_OPTIONS:MOPENGL}
CONFIGURE_ARGS+=	--with-opengl
USE_GL=	glu
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if ${PORT_OPTIONS:MJMA}
CONFIGURE_ARGS+=	--with-jma-decomp
.else
CONFIGURE_ARGS+=	--without-jma-decomp
.endif

.if ${PORT_OPTIONS:MNETPLAY}
CONFIGURE_ARGS+=	--with-netplay
.else
CONFIGURE_ARGS+=	--without-netplay
.endif

.if ${PORT_OPTIONS:MXV}
CONFIGURE_ARGS+=	--with-xv
USE_XORG+=	xv
.else
CONFIGURE_ARGS+=	--without-xv
.endif

.if ${PORT_OPTIONS:MXRANDR}
CONFIGURE_ARGS+=	--with-xrandr
USE_XORG+=	xrandr
.else
CONFIGURE_ARGS+=	--without-xrandr
.endif

.if exists(/usr/lib/libusbhid.a)
CONFIGURE_ARGS+=	--with-joystick
.else
CONFIGURE_ARGS+=	--without-joystick
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.desktop \
		${STAGEDIR}${PREFIX}/share/applications

post-install:
	-@update-desktop-database

.include <bsd.port.post.mk>

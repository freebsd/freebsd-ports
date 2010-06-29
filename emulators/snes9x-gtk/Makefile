# New ports collection makefile for:    snes9x-gtk
# Date created:         2009-12-12
# Whom:                 okeeblow <root@cooltrainer.org>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.52r79
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://snes9x-gtk.googlecode.com/files/
PKGNAMESUFFIX=	-gtk
DISTNAME=	snes9x-1.52-src

MAINTAINER=	root@cooltrainer.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_PERL=	5.8.1+
USE_BZIP2=	yes
USE_XORG=	x11 sm ice xext
USE_GMAKE=	yes
USE_GNOME=	gtk20 desktopfileutils pkgconfig intltool libglade2 libxml2
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_SDL=	sdl
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk

OPTIONS=	DEBUG	"Enable debug information"	off \
		OPENGL	"Enable OpenGL support"	off \
		X86_ASM	"Use i386 optimization (only for i386)"	on \
		MMX	"Enable MMX (only for i386)"	off \
		JMA	"Enable JMA archive decompression support"	on \
		NETPLAY	"Enable network support"	on \
		XV "Enable XVideo output on GTK" on \
		XRANDR "Enable XRandR support on GTK" on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
.else
CONFIGURE_ARGS+=	--without-debug
.endif

.if ${ARCH} == "i386"
.if !defined(WITHOUT_X86_ASM)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.else
CONFIGURE_ARGS+=	--without-assembler
.endif

.if defined(WITH_MMX) && !defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--with-mmx
.else
CONFIGURE_ARGS+=	--without-mmx
.endif
.endif

.if !defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=	--with-opengl
USE_GL=	glu
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !defined(WITHOUT_JMA)
CONFIGURE_ARGS+=	--with-jma-decomp
.else
CONFIGURE_ARGS+=	--without-jma-decomp
.endif

.if !defined(WITHOUT_NETPLAY)
CONFIGURE_ARGS+=	--with-netplay
.else
CONFIGURE_ARGS+=	--without-netplay
.endif

.if !defined(WITHOUT_XV)
CONFIGURE_ARGS+=	--with-xv
USE_XORG+=	xv
.else
CONFIGURE_ARGS+=	--without-xv
.endif

.if !defined(WITHOUT_XRANDR)
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.svg ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.desktop ${PREFIX}/share/applications

post-install:
	-@update-desktop-database

.include <bsd.port.post.mk>

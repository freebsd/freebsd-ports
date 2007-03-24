# New ports collection makefile for:	evas
# Date created:		24 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	20070223
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A hardware-accelerated canvas API for X-Windows

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_FREETYPE2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget

OPTIONS=	GL		"Enable OpenGL rendering backend" off \
		SOFTX11		"Enable software X11 rendering backend" on \
		XRENDER		"Enable XRender X11 rendering backend" on \
		BUFFER		"Enable buffer rendering backend" on \
		DIRECTFB	"Enable DirectFB rendering backend" off \
		FONTCONFIG	"Use fontconfig to find fonts" on \
		GIF		"Enable GIF image loader" on \
		PNG		"Enable PNG image loader" on \
		JPEG		"Enable JPEG image loader" on \
		EET		"Enable EET image loader" on \
		EDB		"Enable EDB image loader" on \
		TIFF		"Enable TIFF image loader" on \
		XPM		"Enable XPM image loader" on \
		SVG		"Enable SVG image loader" on \
		EETFONT		"Enable EET font loader" on

.include <bsd.port.pre.mk>

.if defined(WITH_GL)
CONFIGURE_ARGS+=	--enable-gl-x11
PLIST_SUB+=	WITH_GL=""
USE_GL=		yes
.else
PLIST_SUB+=	WITH_GL="@comment "
.endif

.if defined(WITH_DIRECTFB)
CONFIGURE_ARGS+=	--enable-directfb
PLIST_SUB+=	DIRECTFB=""
LIB_DEPENDS+=	directfb-0.9.16:${PORTSDIR}/devel/directfb
.else
CONFIGURE_ARGS+=	--disable-directfb
PLIST_SUB+=	DIRECTFB="@comment "
.endif

.if !defined(WITHOUT_FONTCONFIG)
CONFIGURE_ARGS+=	--enable-fontconfig
PLIST_SUB+=	FONTCONFIG=""
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
PLIST_SUB+=	FONTCONFIG="@comment "
.endif

.if !defined(WITHOUT_SOFTX11)
CONFIGURE_ARGS+=	--enable-software-x11
PLIST_SUB+=	SOFTX11=""
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=	--disable-software-x11
PLIST_SUB+=	SOFTX11="@comment "
.endif

.if !defined(WITHOUT_XRENDER)
CONFIGURE_ARGS+=	--enable-xrender-x11
PLIST_SUB+=	XRENDER=""
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=	--disable-xrender-x11
PLIST_SUB+=	XRENDER="@comment "
.endif

.if !defined(WITHOUT_BUFFER)
CONFIGURE_ARGS+=	--enable-buffer
PLIST_SUB+=	BUFFER=""
.else
CONFIGURE_ARGS+=	--disable-buffer
PLIST_SUB+=	BUFFER="@comment "
.endif

.if !defined(WITHOUT_GIF)
CONFIGURE_ARGS+=	--enable-image-loader-gif
PLIST_SUB+=	GIF=""
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
.else
CONFIGURE_ARGS+=	--disable-image-loader-gif
PLIST_SUB+=	GIF="@comment "
.endif

.if !defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--enable-image-loader-png
PLIST_SUB+=	PNG=""
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--disable-image-loader-png
PLIST_SUB+=	PNG="@comment "
.endif

.if !defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--enable-image-loader-jpeg
PLIST_SUB+=	JPEG=""
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
CFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-image-loader-jpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if !defined(WITHOUT_EET)
CONFIGURE_ARGS+=	--enable-image-loader-eet
PLIST_SUB+=	EET=""
USE_EFL+=	eet
.else
CONFIGURE_ARGS+=	--disable-image-loader-eet
PLIST_SUB+=	EET="@comment "
.endif

.if !defined(WITHOUT_EETFONT)
CONFIGURE_ARGS+=	--enable-font-loader-eet
PLIST_SUB+=	EETFONT=""
USE_EFL+=	eet
.else
CONFIGURE_ARGS+=	--disable-font-loader-eet
PLIST_SUB+=	EETFONT="@comment "
.endif

.if !defined(WITHOUT_EDB)
CONFIGURE_ARGS+=	--enable-image-loader-edb
PLIST_SUB+=	EDB=""
USE_EFL+=	edb
.else
CONFIGURE_ARGS+=	--disable-image-loader-edb
PLIST_SUB+=	EDB="@comment "
.endif

.if !defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=	--enable-image-loader-tiff
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=	--disable-image-loader-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if !defined(WITHOUT_XPM)
CONFIGURE_ARGS+=	--enable-image-loader-xpm
USE_XPM=	yes
PLIST_SUB+=	XPM=""
.else
CONFIGURE_ARGS+=	--disable-image-loader-xpm
PLIST_SUB+=	XPM="@comment "
.endif

.if !defined(WITHOUT_SVG)
CONFIGURE_ARGS+=	--enable-image-loader-svg
USE_GNOME+=	librsvg2
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
PLIST_SUB+=	SVG=""
.else
CONFIGURE_ARGS+=	--disable-image-loader-svg
PLIST_SUB+=	SVG="@comment "
.endif

.include <bsd.port.post.mk>

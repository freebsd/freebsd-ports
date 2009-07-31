# New ports collection makefile for:	evas-core
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	core
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (core library)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget

CONFIGURE_ARGS=	--disable-software-x11 \
		--disable-software-16-x11 \
		--disable-software-xcb \
		--disable-directfb \
		--disable-sdl \
		--disable-buffer \
		--disable-software-qtopia \
		--disable-gl-x11 \
		--disable-cairo-x11 \
		--disable-xrender-x11 \
		--disable-xrender-xcb \
		--disable-glitz-x11 \
		--disable-image-loader-gif \
		--disable-image-loader-png \
		--disable-image-loader-jpeg \
		--disable-image-loader-eet \
		--disable-image-loader-edb \
		--disable-image-loader-tiff \
		--disable-image-loader-xpm \
		--disable-image-loader-svg \
		--disable-pthreads

OPTIONS=	FONTCONFIG	"Enable fontconfig support" on \
		EET		"Enable EET font loader" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FONTCONFIG)
CONFIGURE_ARGS+=	--enable-fontconfig
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if !defined(WITHOUT_EET)
CONFIGURE_ARGS+=	--enable-font-loader-eet
USE_EFL+=	eet
.else
CONFIGURE_ARGS+=	--disable-font-loader-eet
.endif

.include <bsd.port.post.mk>

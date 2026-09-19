PORTNAME=	Cairo
DISTVERSION=	1.7-0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	R Graphics Device using Cairo Graphics Library
WWW=		https://www.rforge.net/Cairo/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libicuuc.so:devel/icu \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cran:auto-plist,compiles jpeg pkgconfig xorg
USE_XORG=	x11 xext xrender

.include <bsd.port.mk>

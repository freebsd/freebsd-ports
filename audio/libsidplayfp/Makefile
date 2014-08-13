# $FreeBSD$

PORTNAME=	libsidplayfp
PORTVERSION=	1.5.0
CATEGORIES=	audio
MASTER_SITES=	SF/sidplay-residfp/libsidplayfp/${PORTVERSION:R}

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Library to play Commodore 64 music derived from libsidplay2

LICENSE=	GPLv2

USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SIDPLAYFP_SHLIB_VER=	3.0.12
STILVIEW_SHLIB_VER=	0.0.1
PLIST_SUB+=	\
		SIDPLAYFP_SHLIB_MVER=${SIDPLAYFP_SHLIB_VER:C/\.[[:digit:].]+//} \
		SIDPLAYFP_SHLIB_VER=${SIDPLAYFP_SHLIB_VER} \
		STILVIEW_SHLIB_MVER=${STILVIEW_SHLIB_VER:C/\.[[:digit:].]+//} \
		STILVIEW_SHLIB_VER=${STILVIEW_SHLIB_VER}

.include <bsd.port.mk>

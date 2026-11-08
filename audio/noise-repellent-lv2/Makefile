PORTNAME=	noise-repellent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin for broadband noise reduction
WWW=		https://github.com/lucianodato/noise-repellent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		juce>0:devel/juce
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libspecbleach.so:audio/libspecbleach

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	lucianodato

CMAKE_ON=	USE_SYSTEM_JUCE \
		USE_SYSTEM_SPECBLEACH

.include <bsd.port.mk>

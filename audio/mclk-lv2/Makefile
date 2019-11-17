# $FreeBSD$

PORTNAME=	mclk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Midi clock generator LV2 plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	mclk.lv2

PLIST_FILES=	lib/lv2/mclk.lv2/manifest.ttl \
		lib/lv2/mclk.lv2/mclk.so \
		lib/lv2/mclk.lv2/mclk.ttl

.include <bsd.port.mk>

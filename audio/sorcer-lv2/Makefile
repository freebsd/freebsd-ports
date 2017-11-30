# $FreeBSD$

PORTNAME=	Sorcer
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.1.3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wavetable LV2 plugin synth targeted at the electronic/dubstep genre

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs
LIB_DEPENDS=	libntk.so:x11-toolkits/ntk

USES=		cmake:outsource pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	openAVproductions
GH_PROJECT=	openAV-${PORTNAME}
USE_GNOME=	cairo

PLIST_FILES=	lib/lv2/sorcer.lv2/manifest.ttl \
		lib/lv2/sorcer.lv2/sorcer.so \
		lib/lv2/sorcer.lv2/sorcer.ttl

.include <bsd.port.mk>

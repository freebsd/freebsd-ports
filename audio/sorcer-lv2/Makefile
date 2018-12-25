# $FreeBSD$

PORTNAME=	Sorcer
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.1.3
PORTREVISION=	5
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wavetable LV2 plugin synth targeted at the electronic/dubstep genre

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs
LIB_DEPENDS=	libntk.so:x11-toolkits/ntk

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	openAVproductions
GH_PROJECT=	openAV-${PORTNAME}
USE_GNOME=	cairo

PLIST_FILES=	lib/lv2/sorcer.lv2/manifest.ttl \
		lib/lv2/sorcer.lv2/sorcer.so \
		lib/lv2/sorcer.lv2/sorcer.ttl

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_CMAKE_ON=	-DPORT_SIMD_FLAGS:STRING="-msse -mfpmath=sse"

.include <bsd.port.mk>

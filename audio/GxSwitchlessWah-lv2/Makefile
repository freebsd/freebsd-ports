# $FreeBSD$

PORTNAME=	GxSwitchlessWah
DISTVERSION=	g20171206
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analog wah emulation with switchless activation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	${PORTNAME}.lv2
GH_TAGNAME=	6977568

SSE_FLAGS_i386=		"-msse -mfpmath=sse"
SSE_FLAGS_amd64=	"-msse2 -mfpmath=sse"
SSE_FLAGS_armv7=	"-march=armv7 -mfpu=vfpv3"

MAKE_ARGS=	SSE_CFLAGS=${SSE_FLAGS_${ARCH}}

PLIST_FILES=	lib/lv2/GxSwitchlessWah.lv2/gx_switchless_wah.so \
		lib/lv2/GxSwitchlessWah.lv2/gx_switchless_wah.ttl \
		lib/lv2/GxSwitchlessWah.lv2/manifest.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/GxSwitchlessWah.lv2/gx_switchless_wah.so

.include <bsd.port.mk>

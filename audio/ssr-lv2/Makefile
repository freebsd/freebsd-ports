PORTNAME=	ssr
DISTVERSION=	g20210922
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sympathetic string resonator LV2 plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64le powerpc64 powerpc # same as in sysutils/libcpuid because libcpuid is bundled in ssr

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gmake gnome pkgconfig shebangfix xorg
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	jpcima
GH_TAGNAME=	e1999da
GH_TUPLE=	DISTRHO:DPF:220d364:dpf/dpf

SHEBANG_FILES=	dpf/utils/generate-ttl.sh

CFLAGS+=	-I${FILESDIR}

PLIST_FILES=	bin/ssr \
		lib/lv2/ssr.lv2/manifest.ttl \
		lib/lv2/ssr.lv2/ssr_dsp.so \
		lib/lv2/ssr.lv2/ssr_dsp.ttl \
		lib/lv2/ssr.lv2/ssr_ui.so \
		lib/lv2/ssr.lv2/ssr_ui.ttl

.include <bsd.port.mk>

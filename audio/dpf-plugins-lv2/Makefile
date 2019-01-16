# $FreeBSD$

PORTNAME=	dpf-plugins
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-1
PORTREVISION=	4
DISTVERSIONSUFFIX=	-g0c433e4
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of DPF-based LV2 plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	libprojectM.so:graphics/libprojectm

USES=		gmake localbase pkgconfig shebangfix
SHEBANG_FILES=	dpf/utils/generate-ttl.sh
USE_GITHUB=	yes
GH_ACCOUNT=	DISTRHO
GH_PROJECT=	DPF-Plugins
USE_XORG=	x11
USE_GL=		gl

CXXFLAGS+=	-I${FILESDIR}
LDFLAGS+=	-pthread

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_MAKE_ENV=	SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

post-patch: # disable all plugins except for LV2
	@${FIND} ${WRKSRC} -name "*.mk" | ${XARGS} ${REINPLACE_CMD} -i '' -E 's/BUILD_(LADSPA|DSSI|VST2) *= *true/BUILD_\1 = false/'

.include <bsd.port.mk>

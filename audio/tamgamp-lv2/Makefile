PORTNAME=	tamgamp
DISTVERSION=	g20200614
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 guitar amp simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libzita-resampler.so:audio/zita-resampler

USES=		gmake localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sadko4u
GH_PROJECT=	tamgamp.lv2
GH_TAGNAME=	426da74142fcb6b7687a35b2b1dda3392e171b92

BINARY_ALIAS=	make=${GMAKE} # https://github.com/sadko4u/tamgamp.lv2/issues/8

PLIST_FILES=	lib/lv2/tamgamp.lv2/manifest.ttl \
		lib/lv2/tamgamp.lv2/tamgamp-lv2.so \
		lib/lv2/tamgamp.lv2/tamgamp.ttl \
		lib/lv2/tamgamp.lv2/tamgamp_gx.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/tamgamp.lv2/tamgamp-lv2.so

OPTIONS_DEFINE=	SSE AVX

SSE_DESC=	Use SIMD SSE instructions
SSE_MAKE_ARGS=	SSE_INSTR_SET="-mmmx -m3dnow -msse"

AVX_DESC=	Use SIMD AVX instructions
AVX_MAKE_ARGS=	AVX_INSTR_SET="-mavx -mvzeroupper"

.include <bsd.port.mk>

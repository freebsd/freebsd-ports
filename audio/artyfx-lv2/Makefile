PORTNAME=	artyfx
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.3.1
PORTEPOCH=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ArtyFX plugin bundle

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	error: "NEON support not enabled"

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang gnome localbase:ldflags pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	openAVproductions
GH_PROJECT=	openAV-ArtyFX

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_CMAKE_ON=	-DPORT_SIMD_FLAGS:STRING="-msse -msse2 -mfpmath=sse"

CXXFLAGS_powerpc=	-maltivec

post-patch:
	@${REINPLACE_CMD} -e 's| -g | |; s| -O1 | |; s/-msse2 -mfpmath=sse/$${PORT_SIMD_FLAGS}/g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/-msse -msse2 -mfpmath=sse -g/$${PORT_SIMD_FLAGS}/g' \
		${WRKSRC}/src/avtk/CMakeLists.txt

.include <bsd.port.mk>

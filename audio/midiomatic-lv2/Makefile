PORTNAME=	midiomatic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of MIDI filter, generator and processor plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash

USES=		compiler:c++0x gmake pkgconfig shebangfix

SHEBANG_GLOB=	*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	SpotlightKid
GH_TUPLE=	DISTRHO:DPF:ab3e4c3:DISTRHO_DPF/dpf

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_MAKE_ARGS=	PORT_SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst

.include <bsd.port.mk>

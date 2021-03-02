# $FreeBSD$

PORTNAME=	dragonfly-reverb
DISTVERSION=	3.2.3
CATEGORIES=	audio multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bundle of free audio effects

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash

USES=		compiler:c++11-lang gl gmake localbase pkgconfig shebangfix xorg
SHEBANG_FILES=	dpf/utils/generate-ttl.sh
USE_GITHUB=	yes
GH_ACCOUNT=	michaelwillis
GH_TUPLE=	DISTRHO:DPF:1e9e2067caa728fdb0b6d3b0001f37de721b0faa:DISTRHO_DPF/dpf
USE_GL=		gl
USE_XORG=	x11

CXXFLAGS+=	-I${FILESDIR}

EFFECTS=	DragonflyEarlyReflections DragonflyHallReverb DragonflyPlateReverb DragonflyRoomReverb

OPTIONS_DEFINE=		APPS VST
OPTIONS_DEFAULT=	APPS VST
OPTIONS_SUB=		yes

APPS_DESC=		Install apps instantiating effects in Jack sound server
APPS_LIB_DEPENDS=	libjack.so:audio/jack

VST_DESC=		Install VST plugins

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2
.for r in ${EFFECTS}
	cd ${WRKSRC}/bin && ${COPYTREE_SHARE} ${r}.lv2 ${STAGEDIR}${PREFIX}/lib/lv2
.endfor

do-install-APPS-on:
.for r in ${EFFECTS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${r} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-VST-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst
.for r in ${EFFECTS}
	${INSTALL_LIB} ${WRKSRC}/bin/${r}-vst.so ${STAGEDIR}${PREFIX}/lib/vst
.endfor

.include <bsd.port.mk>

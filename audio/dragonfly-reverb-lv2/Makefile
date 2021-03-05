# $FreeBSD$

PORTNAME=	dragonfly-reverb
DISTVERSION=	3.2.5
CATEGORIES=	audio multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bundle of free audio effects

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash

USES=		compiler:c++11-lang gl gmake localbase pkgconfig shebangfix xorg
SHEBANG_FILES=	dpf/utils/generate-ttl.sh
USE_GL=		gl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	michaelwillis
GH_TUPLE=	DISTRHO:DPF:226f219:DISTRHO_DPF/dpf

MAKE_ARGS=	LINUX=true # it fails to set it for BSD for some reason even though the code seems to intend to do this

CXXFLAGS+=	-I${FILESDIR}

EFFECTS=	DragonflyEarlyReflections DragonflyHallReverb DragonflyPlateReverb DragonflyRoomReverb

OPTIONS_DEFINE=		APPS VST
OPTIONS_DEFAULT=	APPS VST
OPTIONS_SUB=		yes

APPS_DESC=		Install apps instantiating effects in Jack sound server
APPS_LIB_DEPENDS=	libjack.so:audio/jack

VST_DESC=		Install VST plugins

# project doesn't have the install target: https://github.com/michaelwillis/dragonfly-reverb/issues/80

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

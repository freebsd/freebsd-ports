PORTNAME=	kars
DISTVERSION=	g20220113
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple karplus-strong plucked string synth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
xLIB_DEPENDS=	libjack.so:audio/jack \
		libpulse.so:audio/pulseaudio

USES=		gmake shebangfix

SHEBANG_FILES=	dpf/utils/generate-ttl.sh

USE_GITHUB=	yes
GH_ACCOUNT=	DISTRHO
GH_PROJECT=	Kars
GH_TAGNAME=	2b247cd
GH_TUPLE=	DISTRHO:DPF:5d7fd17:dpf/dpf

PLIST_FILES=	bin/Kars \
		lib/dssi/Kars-dssi.so \
		lib/lv2/Kars.lv2/Kars_dsp.so \
		lib/lv2/Kars.lv2/Kars_dsp.ttl \
		lib/lv2/Kars.lv2/manifest.ttl \
		lib/vst/Kars-vst.so

do-install: # no install target, same as in https://github.com/DISTRHO/Nekobi/issues/8
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2
	cd ${WRKSRC}/bin && ${COPYTREE_SHARE} Kars.lv2 ${STAGEDIR}${PREFIX}/lib/lv2/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Kars ${STAGEDIR}${PREFIX}/bin
	# VST plugin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst
	${INSTALL_LIB} ${WRKSRC}/bin/Kars-vst.so ${STAGEDIR}${PREFIX}/lib/vst
	# DSSI plugin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/dssi
	${INSTALL_LIB} ${WRKSRC}/bin/Kars-dssi.so ${STAGEDIR}${PREFIX}/lib/dssi

.include <bsd.port.mk>

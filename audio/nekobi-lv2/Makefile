PORTNAME=	nekobi
DISTVERSION=	g20180825
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple single-oscillator synth based on the Roland TB-303

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl gmake localbase pkgconfig shebangfix xorg
SHEBANG_FILES=	dpf/utils/generate-ttl.sh
USE_GITHUB=	yes
GH_ACCOUNT=	DISTRHO
GH_PROJECT=	Nekobi
GH_TAGNAME=	840a692
GH_TUPLE=	DISTRHO:DPF:ea7545a:dpf/dpf
USE_GL=		gl
USE_XORG=	x11

CFLAGS+=	-I${FILESDIR}
CFLAGS+=	-Wno-c++11-narrowing # clang prints errors: https://github.com/DISTRHO/Nekobi/issues/7

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	@${REINPLACE_CMD} -e 's/-mtune=generic -msse -msse2 //' \
		${WRKSRC}/dpf/Makefile.base.mk
.endif

do-install: # https://github.com/DISTRHO/Nekobi/issues/8
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2
	cd ${WRKSRC}/bin && ${COPYTREE_SHARE} Nekobi.lv2 ${STAGEDIR}${PREFIX}/lib/lv2/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Nekobi ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>

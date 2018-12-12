# $FreeBSD$

PORTNAME=	zam-plugins
DISTVERSION=	3.10-13
DISTVERSIONSUFFIX=	-gfbdbf08
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LADSPA/LV2/VST/JACK audio plugins

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libsamplerate.so:audio/libsamplerate \
		libzita-convolver.so:audio/zita-convolver

USES=		compiler:c++11-lib gl gmake localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	zamaudio
GH_TUPLE=	DISTRHO:DPF:2786991:d/dpf
USE_GL=		gl
USE_XORG=	x11

CFLAGS+=	-I${FILESDIR}
MAKE_ARGS+=	USE_SYSTEM_LIBS=1
xLDFLAGS+=	-lzita-convolver # TODO this can be reduced to only relevant places

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -r ${WRKSRC}/lib/zita-convolver-*

post-patch:
	#@${REINPLACE_CMD} -e 's|#include "../../lib/zita-convolver-.*/zita-convolver.h"|#include <zita-convolver.h>|' ${WRKSRC}/plugins/Zam*/convolution.*pp
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' ${WRKSRC}/dpf/utils/generate-ttl.sh
.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
	${REINPLACE_CMD} -e '/-mfpmath=sse/d' \
		-e 's/-mtune=generic -msse -msse2//' \
		${WRKSRC}/Makefile.mk ${WRKSRC}/dpf/dgl/Makefile.mk
.endif

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	zam-plugins
DISTVERSION=	3.11-1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gce45995
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LADSPA/LV2/VST/JACK audio plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libsamplerate.so:audio/libsamplerate \
		libzita-convolver.so:audio/zita-convolver

USES=		compiler:c++11-lib gl gmake localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	zamaudio
GH_TUPLE=	DISTRHO:DPF:68b3a57:d/dpf
USE_GL=		gl
USE_XORG=	x11

CFLAGS+=	-I${FILESDIR}
MAKE_ARGS+=	USE_SYSTEM_LIBS=1 HAVE_ZITA_CONVOLVER=true

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -r ${WRKSRC}/lib/zita-convolver-*

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' ${WRKSRC}/dpf/utils/generate-ttl.sh
	${REINPLACE_CMD} -e 's/-mtune=generic//' \
		${WRKSRC}/dpf/Makefile.base.mk
.if ! ${ARCH} == amd64 && ! ${ARCH} == i386
	${REINPLACE_CMD} -e 's/-msse -msse2//' \
		${WRKSRC}/dpf/Makefile.base.mk
.endif

.include <bsd.port.post.mk>

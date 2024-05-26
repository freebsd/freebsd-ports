PORTNAME=	zam-plugins
DISTVERSION=	4.3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LADSPA/LV2/VST/JACK audio plugins
WWW=		https://www.zamaudio.com/?p=976

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libpulse.so:audio/pulseaudio \
		libsamplerate.so:audio/libsamplerate \
		libzita-convolver.so:audio/zita-convolver

USES=		compiler:c++11-lib gl gmake localbase:ldflags pkgconfig sdl xorg
USE_GL=		gl
USE_SDL=	sdl2
USE_XORG=	x11 xext xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	zamaudio
GH_TUPLE=	DISTRHO:DPF:077fcf5:DISTRHO_DPF/dpf \
		DISTRHO:pugl:e33b2f6:DISTRHO_DPF_pugl/dpf/dgl/src/pugl-upstream

CFLAGS+=	-I${FILESDIR}
MAKE_ARGS+=	USE_SYSTEM_LIBS=1 HAVE_ZITA_CONVOLVER=true

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -r ${WRKSRC}/lib/zita-convolver-*

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|' ${WRKSRC}/dpf/utils/generate-ttl.sh
	${REINPLACE_CMD} -e 's/-mtune=generic//' \
		${WRKSRC}/dpf/Makefile.base.mk
.if ! ${ARCH} == amd64 && ! ${ARCH} == i386
	${REINPLACE_CMD} -e 's/-msse -msse2//' \
		${WRKSRC}/dpf/Makefile.base.mk
.endif

.include <bsd.port.post.mk>

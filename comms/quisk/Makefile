# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quisk
DISTVERSION=	4.1.40
PORTREVISION=	5
CATEGORIES=	comms hamradio
MASTER_SITES=	CHEESESHOP

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software Defined Radio (SDR)

LICENSE=	GPLv2

BROKEN_i386=	strip: elf_update() failed: Invalid data buffer descriptor (bug#238131)

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libportaudio.so:audio/portaudio \
		libasound.so:audio/alsa-lib \
		libpulse.so:audio/pulseaudio

USES=		python:2.7
USE_PYTHON=	distutils noflavors autoplist
USE_WX=		3.0+

WX_COMPS=	python

post-extract:
	@${RM} ${WRKSRC}/_quisk.so ${WRKSRC}/sdriqpkg/sdriq.so \
		${WRKSRC}/freedvpkg/libcodec2_32.so \
		${WRKSRC}/freedvpkg/libcodec2_64.so

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

post-stage:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>

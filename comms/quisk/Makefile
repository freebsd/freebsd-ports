# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quisk
PORTVERSION=	4.1.26
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	CHEESESHOP

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software Defined Radio (SDR)

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libportaudio.so:audio/portaudio \
		libasound.so:audio/alsa-lib \
		libpulse.so:audio/pulseaudio

USES=		python:2.7
USE_PYTHON=	distutils autoplist
USE_WX=		3.0+

WX_COMPS=	python

post-extract:
	${RM} ${WRKSRC}/_quisk.so ${WRKSRC}/sdriqpkg/sdriq.so \
		${WRKSRC}/freedvpkg/libcodec2_32.so \
		${WRKSRC}/freedvpkg/libcodec2_64.so

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>

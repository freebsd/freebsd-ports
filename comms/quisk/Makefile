# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quisk
PORTVERSION=	3.6.18
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://james.ahlstrom.name/quisk/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=shurd

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Software Defined Radio (SDR)

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libpulse.so:${PORTSDIR}/audio/pulseaudio

USE_PYTHON=	yes
USE_WX=		3.0+
WX_COMPS=	python
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${RM} ${WRKSRC}/_quisk.so ${WRKSRC}/sdriqpkg/sdriq.so

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>

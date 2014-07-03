# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quisk
PORTVERSION=	3.6.18
CATEGORIES=	comms hamradio
MASTER_SITES=	http://james.ahlstrom.name/quisk/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=shurd

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	A Software Defined Radio (SDR)

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libpulse.so:${PORTSDIR}/audio/pulseaudio

USE_PYTHON=	2.7+
USE_WX=		2.8+
WANT_UNICODE=	yes
WX_COMPS=	python
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${RM} ${WRKSRC}/_quisk.so ${WRKSRC}/sdriqpkg/sdriq.so

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>

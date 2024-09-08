PORTNAME=	quisk
DISTVERSION=	4.2.36
CATEGORIES=	comms hamradio
MASTER_SITES=	PYPI

MAINTAINER=	fbsd@thesoo.org
COMMENT=	Software Defined Radio (SDR)
WWW=		https://james.ahlstrom.name/quisk/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio

USES=		python
USE_PYTHON=	autoplist distutils noflavors
USE_WX=		3.2

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

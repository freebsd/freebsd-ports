PORTNAME=	pulsectl
DISTVERSION=	21.10.5
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Python high-level interface and ctypes-based bindings for PulseAudio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	pyttsx3
DISTVERSION=	2.91
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Offline Text To Speech (TTS) converter for Python
WWW=		https://github.com/nateshmbhat/pyttsx3

LICENSE=	MPL20

LIB_DEPENDS=	libespeak.so:audio/espeak-ng

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	pyttsx3
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.90-12
DISTVERSIONSUFFIX=	-g5d3755b
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Offline Text To Speech (TTS) converter for Python
WWW=		https://github.com/nateshmbhat/pyttsx3

LICENSE=	MPL20

LIB_DEPENDS=	libespeak.so:audio/espeak-ng

# Unfortunately found no way to use PyPI
USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	nateshmbhat
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

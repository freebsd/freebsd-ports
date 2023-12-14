PORTNAME=	speechrecognition
PORTVERSION=	3.10.1
MASTER_SITES=	PYPI
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SpeechRecognition-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Library for performing speech recognition
WWW=		https://github.com/Uberi/speech_recognition

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	flac:audio/flac \
		${PYTHON_PKGNAMEPREFIX}pyaudio>=0.2.11:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/speech_recognition/flac-*

.include <bsd.port.mk>

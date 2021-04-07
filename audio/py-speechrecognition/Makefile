PORTNAME=	SpeechRecognition
PORTVERSION=	3.8.1
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Library for performing speech recognition

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes 
GH_ACCOUNT=	Uberi
GH_PROJECT=	speech_recognition

RUN_DEPENDS=	flac:audio/flac \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-extract:       
	@cd ${WRKSRC}/speech_recognition && ${RM} flac-*

.include <bsd.port.mk>

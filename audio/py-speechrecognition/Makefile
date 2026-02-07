PORTNAME=	speechrecognition
PORTVERSION=	3.10.3
MASTER_SITES=	PYPI
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SpeechRecognition-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Library for performing speech recognition
WWW=		https://github.com/Uberi/speech_recognition

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	flac:audio/flac \
		${PYTHON_PKGNAMEPREFIX}pyaudio>=0.2.11:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# Clean up bundled binary executables
.if !defined(MAINTAINER_MODE)
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/speech_recognition/flac-* \
			--no-same-owner --no-same-permissions
.else
post-patch:
	@${RM} ${WRKSRC}/speech_recognition/flac-*
.endif

.include <bsd.port.mk>

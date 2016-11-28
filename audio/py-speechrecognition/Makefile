# $FreeBSD$

PORTNAME=	SpeechRecognition
PORTVERSION=	3.5.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Python Library for performing speech recognition

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	flac:audio/flac \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}monotonic>=0.3:devel/py-monotonic
.endif

.include <bsd.port.post.mk>

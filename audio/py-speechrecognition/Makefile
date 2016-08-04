# $FreeBSD$

PORTNAME=	speechrecognition
PORTVERSION=	3.4.6
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
DISTNAME=	${PORTNAME:S/s/S/:S/r/R/}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Python Library for performing speech recognition

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	flac:audio/flac \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

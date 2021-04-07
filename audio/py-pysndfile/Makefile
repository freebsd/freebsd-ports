PORTNAME=	pysndfile
DISTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython wrapper class for reading/writing soundfiles using libsndfile

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.6+ localbase
USE_PYTHON=	distutils autoplist cython

.include <bsd.port.mk>

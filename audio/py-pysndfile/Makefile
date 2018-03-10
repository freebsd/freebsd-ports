# $FreeBSD$

PORTNAME=	pysndfile
DISTVERSION=	1.1.0
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

USES=		python localbase
USE_PYTHON=	distutils autoplist cython

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysndfile/_pysndfile.so

.include <bsd.port.mk>

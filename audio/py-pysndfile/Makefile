# $FreeBSD$

PORTNAME=	pysndfile
DISTVERSION=	1.0.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython wrapper class for reading/writing soundfiles using libsndfile

LICENSE=	LGPL3

BUILD_DEPENDS=	cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy
LIB_DEPENDS=	libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy

USES=		python localbase
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysndfile/_pysndfile.so

.include <bsd.port.mk>

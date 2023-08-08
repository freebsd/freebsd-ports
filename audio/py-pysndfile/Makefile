PORTNAME=	pysndfile
DISTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython wrapper class for reading/writing soundfiles using libsndfile
WWW=		https://forge-2.ircam.fr/roebel/pysndfile

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYNUMPY}

USES=		python localbase
USE_PYTHON=	distutils autoplist cython

.include <bsd.port.mk>

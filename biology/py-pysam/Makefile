PORTNAME=	pysam
DISTVERSION=	0.20.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets
WWW=		https://github.com/pysam-developers/pysam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake python:3.6-3.9
USE_PYTHON=	autoplist distutils cython cython_run pytest

CFLAGS+=	-fPIC # workaround for https://github.com/pysam-developers/pysam/issues/1146

BINARY_ALIAS=	make=${GMAKE}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysam/lib*${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

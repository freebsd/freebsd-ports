PORTNAME=	cython
PORTVERSION=	0.29.37
PORTREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	PYPI \
		https://github.com/cython/cython/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cython-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language
WWW=		https://cython.org/ \
		https://github.com/cython/cython

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 python:2.7-3.12
USE_PYTHON=	allflavors autoplist concurrent distutils

CONFLICTS_INSTALL=	py*-cython3 # bin/cygdb bin/cython bin/cythonize

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

PORTNAME=	cython
PORTVERSION=	0.29.37
CATEGORIES=	lang python
MASTER_SITES=	PYPI \
		https://github.com/cython/cython/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	0
DISTNAME=	Cython-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language
WWW=		https://cython.org/ \
		https://github.com/cython/cython

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECTED=	Legacy version. Does not work with newer Python versions. Use lang/cython instead
EXPIRATION_DATE=2026-03-31

USES=		compiler:c11 python:2.7-3.12
USE_PYTHON=	allflavors autoplist concurrent distutils

CONFLICTS_INSTALL=	py*-cython py*-cython3 # bin/cygdb bin/cython bin/cythonize

PORTSCOUT=	limit:^0\.

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

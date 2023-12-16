PORTNAME=	cython
PORTVERSION=	3.0.6
CATEGORIES=	lang python
MASTER_SITES=	PYPI \
		https://github.com/cython/cython/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cython-${PORTVERSION}
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language
WWW=		https://cython.org/ \
		https://github.com/cython/cython

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 python
USE_PYTHON=	allflavors autoplist concurrent distutils

# bin/cygdb bin/cython bin/cythonize
CONFLICTS_INSTALL=	py*-cython py*-cython-devel

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

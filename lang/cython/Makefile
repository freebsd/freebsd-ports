# Created by: Wen Heping <wenhping@gmail.com>

PORTNAME=	cython
PORTVERSION=	0.29.24
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cython-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 python:2.7-3.10
USE_PYTHON=	allflavors autoplist concurrent distutils

CONFLICTS_INSTALL=	py*-cython-devel # bin/cygdb bin/cygdb-3.8 bin/cython bin/cython-3.8 bin/cythonize bin/cythonize-3.8

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

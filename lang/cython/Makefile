# Created by: Wen Heping <wenhping@gmail.com>

PORTNAME=	cython
PORTVERSION=	0.29.27
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cython-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 python:2.7+
USE_PYTHON=	allflavors autoplist concurrent distutils

# bin/cygdb bin/cython bin/cythonize
CONFLICTS_INSTALL=	py*-cython-devel

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

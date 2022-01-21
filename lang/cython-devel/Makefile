PORTNAME=	cython
DISTVERSION=	3.0.0a10
CATEGORIES=	lang python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 python:2.7+
USE_PYTHON=	allflavors autoplist concurrent distutils
USE_GITHUB=	yes

CONFLICTS_INSTALL=	py*-cython # bin/cygdb bin/cygdb-3.8 bin/cython bin/cython-3.8 bin/cythonize bin/cythonize-3.8

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31100
BROKEN=		does not yet support python 3.11.0a4
.endif

.include <bsd.port.post.mk>

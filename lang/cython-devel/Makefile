PORTNAME=	cython
DISTVERSION=	3.0.4
CATEGORIES=	lang python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Compiler for Writing C Extensions for the Python Language
WWW=		https://cython.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	use devel/cython3
EXPIRATION_DATE=2024-04-11

USES=		compiler:c11 python
USE_PYTHON=	allflavors autoplist concurrent distutils
USE_GITHUB=	yes

CONFLICTS_INSTALL=	py*-cython # bin/cygdb bin/cygdb-3.8 bin/cython bin/cython-3.8 bin/cythonize bin/cythonize-3.8
CFLAGS+=	-Wno-unreachable-code

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Cython -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${SETENV} XDG_CACHE_HOME="${WRKDIR}" ${PYTHON_CMD} runtests.py -vv

.include <bsd.port.mk>

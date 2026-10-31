PORTNAME=	unrardll
DISTVERSION=	0.1.7
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Python wrapper for the UnRAR DLL
WWW=		https://github.com/kovidgoyal/unrardll

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libunrar.so:archivers/libunrar

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	UNRAR_INCLUDE=${LOCALBASE}/include \
		UNRAR_LIBDIRS=${LOCALBASE}/lib
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest -v test.basic

.include <bsd.port.mk>

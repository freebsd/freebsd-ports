PORTNAME=	zstd
DISTVERSION=	1.5.1.0
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Zstandard compression library

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libzstd.so:archivers/zstd
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+ localbase
USE_PYTHON=	distutils autoplist

PYDISTUTILS_BUILDARGS=	--external

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zstd*.so

do-test: install
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>

PORTNAME=	redisvl
DISTVERSION=	0.12.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Python client library and CLI for using Redis as a vector database
WWW=		https://github.com/redis/redis-vl-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4<7.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis6>=5.0<7.0:databases/py-redis6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.2.2:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ml-dtypes>=0.4.0<1.0.0:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ulid>=3.0.0:textproc/py-python-ulid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpath-ng>=1.5.0:devel/py-jsonpath-ng@${PY_FLAVOR}

USES=		python

USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

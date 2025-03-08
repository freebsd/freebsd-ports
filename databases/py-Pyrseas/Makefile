PORTNAME=	Pyrseas
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arcade@b1t.name
COMMENT=	Framework and utilities to upgrade and maintain a relational database
WWW=		https://github.com/perseas/Pyrseas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg>=3.1:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	perseas
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Requires a running PostgreSQL instance

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>

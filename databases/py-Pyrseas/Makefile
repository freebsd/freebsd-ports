# $FreeBSD$

PORTNAME=	Pyrseas
PORTVERSION=	0.7.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arcade@b1t.name
COMMENT=	Framework and utilities to upgrade and maintain a relational database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.2:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.09:${PORTSDIR}/devel/py-yaml
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	perseas
GH_COMMIT=	9b0e3d2
GH_TAGNAME=	v${PORTVERSION}

# Requires a running PostgreSQL instance

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>

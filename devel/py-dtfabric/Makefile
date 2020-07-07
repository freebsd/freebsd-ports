# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dtfabric
PORTVERSION=	20200621
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
#		https://github.com/libyal/dtfabric/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tooling for data type and structure management

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.5+
USE_PYTHON=	distutils autoplist concurrent

post-patch:
	${REINPLACE_CMD} "s,share/doc/dtfabric,${DOCSDIR_REL}," ${WRKSRC}/setup.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests.py)

.include <bsd.port.mk>

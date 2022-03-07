# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	cloudpickle
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended pickling support for Python objects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Need -s for https://github.com/cloudpipe/cloudpickle/issues/252
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -s

.include <bsd.port.mk>

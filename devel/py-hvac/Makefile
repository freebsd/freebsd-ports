# Created by: Alessando Sagratini <ale_sagra@hotmail.com>
# $FreeBSD$

PORTNAME=	hvac
PORTVERSION=	0.10.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ale_sagra@hotmail.com
COMMENT=	HashiCorp Vault API client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyhcl>=0.3.10:devel/py-pyhcl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>2.21.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m tox

.include <bsd.port.mk>

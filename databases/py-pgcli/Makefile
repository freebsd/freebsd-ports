# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pgcli
PORTVERSION=	3.1.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for Postgres Database with auto-completion and syntax highlighting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=2.0.0:devel/py-cli-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pendulum>=2.1.0:devel/py-pendulum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pgspecial>=1.11.8:databases/py-pgspecial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=2.0.6<4.0.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.9:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.3.0<0.5:databases/py-sqlparse@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.7.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect@${PY_FLAVOR}

USES=		pgsql python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	KEYRING
KEYRING_DESC=	keyring support

KEYRING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>=12.2.0,1:security/py-keyring@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>

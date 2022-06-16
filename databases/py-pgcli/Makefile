# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pgcli
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for Postgres Database with auto-completion and syntax highlighting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=2.1.1:devel/py-cli-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pendulum>=2.1.0:devel/py-pendulum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pgspecial1>=1.13.1<2.0.0:databases/py-pgspecial1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=2.0.6<4.0.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.9:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.3.0<0.5:databases/py-sqlparse@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sshtunnel>=0:net/py-sshtunnel@${PY_FLAVOR}

USES=		pgsql python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
PYTEST_BROKEN_TESTS=	test_obfuscate_process_password

OPTIONS_DEFINE=	KEYRING
KEYRING_DESC=	keyring support

KEYRING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>=12.2.0,1:security/py-keyring@${PY_FLAVOR}

.include <bsd.port.mk>

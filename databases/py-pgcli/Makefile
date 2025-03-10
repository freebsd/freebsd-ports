PORTNAME=	pgcli
PORTVERSION=	4.1.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for Postgres Database with auto-completion and syntax highlighting
WWW=		https://www.pgcli.com/ \
		https://github.com/dbcli/pgcli

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=2.1.1:devel/py-cli-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pgspecial>=2.0.0:databases/py-pgspecial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=2.0.6<4.0.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.0.14:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.9:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.3.0<0.6:databases/py-sqlparse@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sshtunnel>=0:net/py-sshtunnel@${PY_FLAVOR}

USES=		pgsql python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
PYTEST_BROKEN_TESTS=	test_obfuscate_process_password

OPTIONS_DEFINE=	KEYRING SSHTUNNEL
KEYRING_DESC=	keyring support
SSHTUNNEL_DESC=	SSH tunnel support

KEYRING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>=12.2.0,1:security/py-keyring@${PY_FLAVOR}
SSHTUNNEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sshtunnel>=0:net/py-sshtunnel@${PY_FLAVOR}

.include <bsd.port.mk>

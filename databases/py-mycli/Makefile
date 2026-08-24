PORTNAME=	mycli
PORTVERSION=	1.76.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for MySQL Database with auto-completion and syntax highlighting
WWW=		https://www.mycli.net/ \
		https://github.com/dbcli/mycli

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=2.15.0<2.16:devel/py-cli-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.3.1<8.4:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}clickdc>=0.1.1<0.2:devel/py-clickdc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.9<5.1:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=25.6.0,1<25.8,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.41<4.0.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.23.0<3.24:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyfzf>=0.3.1<0.4:textproc/py-pyfzf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.19.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>=1.1.2:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.11.0<1.12:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.14.3<3.15:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglot>=30.8.0:databases/py-sqlglot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglotc>=30.8.0:databases/py-sqlglotc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.3.0<0.6.0:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.6.0:devel/py-wcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaspin>=3.4.0<3.5:devel/py-yaspin@${PY_FLAVOR}

USES=		cpe mysql python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

CPE_VENDOR=	dbcli

OPTIONS_DEFINE=	SSH

SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=3.5.1<3.6:security/py-paramiko@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sshtunnel>=0.4.0<0.5:net/py-sshtunnel@${PY_FLAVOR}

.include <bsd.port.mk>

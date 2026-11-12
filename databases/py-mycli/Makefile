PORTNAME=	mycli
PORTVERSION=	2.30.3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rich MySQL terminal client with autocompletion, syntax highlighting, and dataframes
WWW=		https://www.mycli.net/ \
		https://github.com/dbcli/mycli

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=2.15.3<2.16:devel/py-cli-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.5.0<8.6:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}clickdc>=0.1.1<0.2:devel/py-clickdc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.9<5.1:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6<3.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=25.6.0,1<25.8,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=3.0.4<3.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.53<4.0.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.24.1<3.25:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.21.0<2.22:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>=1.2.0<1.3:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.14.6<3.15:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglot>=30.23.0:databases/py-sqlglot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglotc>=30.23.0:databases/py-sqlglotc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.6.0<0.7:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.9.4<0.10:devel/py-wcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaspin>=3.5.1<3.6:devel/py-yaspin@${PY_FLAVOR}

USES=		cpe mysql python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

CPE_VENDOR=	dbcli

.include <bsd.port.mk>

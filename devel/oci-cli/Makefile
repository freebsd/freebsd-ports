PORTNAME=	oci-cli
DISTVERSION=	3.36.2
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ale_sagra@hotmail.com
COMMENT=	Command Line Interface for Oracle Cloud Infrastructure
WWW=		https://github.com/oracle/oci-cli/

LICENSE=	APACHE20 UPL
LICENSE_COMB=	dual
LICENSE_GROUPS_UPL=	FSF GPL OSI
LICENSE_NAME_UPL=	Universal Permissive License
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_UPL=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_UPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=1.0.0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0.4:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.5.3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.10.0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oci>=2.116.0:devel/py-oci@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=22.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.29:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.10:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.4:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminaltables>=3.1.0:textproc/py-terminaltables@${PY_FLAVOR}

USES=		python:3.8-3.11
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>

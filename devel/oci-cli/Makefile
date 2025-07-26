PORTNAME=	oci-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	3.63.0
CATEGORIES=	devel
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=1.0.0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0.4:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.10.0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oci>=2.156.0:devel/py-oci@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=22.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.29:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.5.3:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.10:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminaltables>=3.1.0:textproc/py-terminaltables@${PY_FLAVOR}

USES=		python:3.9-3.12
USE_GITHUB=	yes
GH_ACCOUNT=	oracle
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>

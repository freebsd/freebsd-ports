PORTNAME=	oci
DISTVERSION=	2.156.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ale_sagra@hotmail.com
COMMENT=	Python interface to Oracle Cloud Infrastructure
WWW=		https://github.com/oracle/oci-python-sdk/

LICENSE=	APACHE20 UPL
LICENSE_COMB=	dual
LICENSE_GROUPS_UPL=	FSF GPL OSI
LICENSE_NAME_UPL=	Universal Permissive License
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_UPL=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_UPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}circuitbreaker>=1.3.1:devel/py-circuitbreaker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.16:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>=1.6.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=17.5.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10.6:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.5.3<3.0.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.10:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.9.4:textproc/py-rich@${PY_FLAVOR}

USES=		python:3.9-3.12
USE_PYTHON=	autoplist cryptography pep517

NO_ARCH=	yes

# The testsuite isn't available in the sdist through PyPI, yet.  Switching to
# GitHub doesn't help either because the testsuite doesn't work outside
# virtualenvs at the moment.
# See also: https://github.com/oracle/oci-python-sdk/issues/164
# do-test:

.include <bsd.port.mk>

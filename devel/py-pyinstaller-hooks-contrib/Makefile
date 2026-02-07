PORTNAME=	pyinstaller-hooks-contrib
DISTVERSION=	2023.12
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hsw@bitmark.com
COMMENT=	Community maintained hooks for pyinstaller
WWW=		https://pypi.org/project/pyinstaller-hooks-contrib/

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APL.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}towncrier>0:textproc/py-towncrier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twine>0:devel/py-twine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}execnet>0:sysutils/py-execnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinstaller>0:devel/py-pyinstaller@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-drop-dup-tests>0:devel/py-pytest-drop-dup-tests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions

NO_ARCH=	yes

.include <bsd.port.mk>

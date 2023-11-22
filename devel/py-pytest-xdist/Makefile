PORTNAME=	pytest-xdist
PORTVERSION=	3.5.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pytest xdist plugin for distributed testing and loop-on-failing modes
WWW=		https://github.com/pytest-dev/pytest-xdist

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.2.3:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}execnet>=1.1:sysutils/py-execnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=6.2.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=0:sysutils/py-filelock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		PSUTIL SETPROCTITLE
OPTIONS_DEFAULT=	PSUTIL SETPROCTITLE

PSUTIL_DESC=		Detect number of available CPUs
SETPROCTITLE_DESC=	Indicate state of current running workers

PSUTIL_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}psutil>=3.0:sysutils/py-psutil@${PY_FLAVOR}
SETPROCTITLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}

.include <bsd.port.mk>

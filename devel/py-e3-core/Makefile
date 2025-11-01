PORTNAME=	e3-core
DISTVERSION=	22.10.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Core framework for developing portable automated build systems
WWW=		https://github.com/AdaCore/e3-core

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-cache>0:www/py-requests-cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resolvelib>0:devel/py-resolvelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		bash>0:shells/bash
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansi2html>0:textproc/py-ansi2html@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ptyprocess>0:sysutils/py-ptyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-html>0:devel/py-pytest-html@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		git>0:devel/git \
		rsync>0:net/rsync

USES=		pytest python
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
USE_PYTHON=	autoplist concurrent pep517

PLIST_FILES+=	${PYTHON_SITELIBDIR}/e3/os/data/rlimit-${_RLIMIT_PLATFORM}

_RLIMIT_PLATFORM=	${ARCH:S/amd64/x86_64/}-${OPSYS:tl}

post-patch:
# Modify ${WRKSRC}/VERSION to reflect the complete upsteam version, to avoid
# dealing with Python Wheel shenanigans
	${REINPLACE_CMD} -e 's|${PORTVERSION:R}|${PORTVERSION}|' \
		${WRKSRC}/VERSION
	${REINPLACE_CMD} -e 's|%%PYTHON_VER%%|${PYTHON_VER}|' \
		${WRKSRC}/tests/tests_e3/os/process/main_test.py \
		${WRKSRC}/tests/tests_e3/main/main_test.py

pre-build:
# Build required rlimit binary, see GitHub issue 388 for context,
# https://github.com/AdaCore/e3-core/issues/388
	(cd ${WRKSRC}/tools/rlimit && \
		${CC} -o rlimit-${_RLIMIT_PLATFORM} rlimit.c)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rlimit/rlimit-${_RLIMIT_PLATFORM} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/e3/os/data/

do-test:
# Tests require e3 to function
	(cd ${WRKSRC} && \
		${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>

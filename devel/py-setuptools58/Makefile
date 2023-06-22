PORTNAME=	setuptools
PORTVERSION=	58.5.3
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	58
DIST_SUBDIR=	python

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer
WWW=		https://pypi.org/project/setuptools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	allflavors autoplist concurrent pep517 pytest

CPE_VENDOR=	python

NO_ARCH=	yes

# pkg install -y py38-pytest py38-mock py38-pytest-fixture-config py38-pytest-virtualenv py38-paver

.include <bsd.port.mk>

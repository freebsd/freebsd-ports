PORTNAME=	grimoirelab-toolkit
DISTVERSION=	1.0.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	grimoirelab_toolkit-${DISTVERSION}

# Ask clusteradm@ before removal
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit of common functions used across GrimoireLab projects
WWW=		https://github.com/chaoss/grimoirelab-toolkit/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>

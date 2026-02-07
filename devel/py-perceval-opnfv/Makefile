PORTNAME=	perceval-opnfv
DISTVERSION=	1.0.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

# Ask clusteradm@ before removal
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bundle of Perceval backends for OPNFV ecosystem
WWW=		https://github.com/chaoss/grimoirelab-perceval-opnfv

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=1.0.9:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval>=1.1.1:devel/py-perceval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpretty>0:www/py-httpretty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest2
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>

PORTNAME=	perceval-puppet
DISTVERSION=	1.0.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Bundle of Perceval backends for Puppet ecosystem
WWW=		https://github.com/chaoss/grimoirelab-perceval-puppet

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=0.3:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval>=0.19:devel/py-perceval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpretty>0:www/py-httpretty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest2
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>

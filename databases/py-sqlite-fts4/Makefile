PORTNAME=	sqlite-fts4
PORTVERSION=	1.0.3
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Python functions for working with SQLite FTS4 search
WWW=		https://github.com/simonw/sqlite-fts4

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	simonw
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>

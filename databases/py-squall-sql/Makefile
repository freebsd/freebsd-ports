PORTNAME=	squall-sql
DISTVERSION=	0.1.8
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TUI SQLite Viewer and Editor
WWW=		https://github.com/driscollis/squall

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.17.1:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	py311-rich>=14.3.2:textproc/py-rich@${PY_FLAVOR} \
		py311-sqlalchemy20>=2.0.46:databases/py-sqlalchemy20@${PY_FLAVOR} \
		py311-textual>=6.12.0:textproc/py-textual@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

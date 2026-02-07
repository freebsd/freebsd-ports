PORTNAME=	harlequin-mysql
DISTVERSION=	1.3.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	MySQL adapter for Harlequin, the SQL IDE for your Terminal
WWW=		https://github.com/tconbeer/harlequin-mysql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.28.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}duckdb>=1.3.2:databases/py-duckdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}harlequin>=2.5.1:databases/py-harlequin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysql-connector-python>=9.5.0:databases/py-mysql-connector-python@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

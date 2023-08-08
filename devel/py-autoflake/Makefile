PORTNAME=	autoflake
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Removes unused imports and unused variables from Python code
WWW=		https://github.com/PyCQA/autoflake

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyflakes>=1.1.0:devel/py-pyflakes@${PY_FLAVOR}

USES=		pytest python shebangfix
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	autoflake.py test_autoflake.py

NO_ARCH=	yes

.include <bsd.port.mk>

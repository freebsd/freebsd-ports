PORTNAME=	lance-namespace
PORTVERSION=	0.13.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lance Namespace interface and plugin registry
WWW=		https://lance.org/format/namespace/ \
		https://github.com/lance-format/lance-namespace

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lance-namespace-urllib3-client>=0.13.0:databases/py-lance-namespace-urllib3-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.13.0: 13 passed in 0.65s

.include <bsd.port.mk>

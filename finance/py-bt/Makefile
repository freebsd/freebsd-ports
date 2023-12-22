PORTNAME=	bt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible backtesting framework to test quantitative trading strategies
WWW=		http://pmorissette.github.io/bt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ffn>=0.3.5:finance/py-ffn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyprind>=2.11:misc/py-pyprind@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests require nose which is currently broken

USE_GITHUB=	yes
GH_ACCOUNT=	pmorissette

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bt/core${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

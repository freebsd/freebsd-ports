PORTNAME=	bt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible backtesting framework to test quantitative trading strategies
WWW=		http://pmorissette.github.io/bt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ffn>=1.1.0:finance/py-ffn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyprind>=2.11:misc/py-pyprind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pmorissette

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bt/core${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

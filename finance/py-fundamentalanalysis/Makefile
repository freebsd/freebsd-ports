PORTNAME=	fundamentalanalysis
PORTVERSION=	0.3.1
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fundamental analysis package to analyze companies data
WWW=		https://github.com/JerBouma/FundamentalAnalysis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}financedatabase>=2.2.0:finance/py-financedatabase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}financetoolkit>=1.3.5:finance/py-financetoolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1.2:math/py-pandas@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	logistro
DISTVERSION=	1.0.11
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple wrapper over logging for a couple basic features
WWW=		https://github.com/geopozo/logistro

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-patch: # workaround for https://github.com/plotly/Kaleido/issues/288
	@${REINPLACE_CMD} -e "s|version = \"0.0.0\"|version = \"${DISTVERSION}\"|" ${WRKSRC}/pyproject.toml

# tests as of 1.0.11:
# Results (18.81s):
#       17 passed

.include <bsd.port.mk>

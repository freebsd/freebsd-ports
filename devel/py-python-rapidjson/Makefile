PORTNAME=	python-rapidjson
DISTVERSION=	1.19
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper around rapidjson
WWW=		https://github.com/python-rapidjson/python-rapidjson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rapidjson${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

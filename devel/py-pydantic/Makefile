PORTNAME=	pydantic
DISTVERSION=	1.10.13
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data validation and settings management using python 3.6 type hinting
WWW=		https://github.com/samuelcolvin/pydantic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	distutils cython autoplist pytest # tests fail to run, see https://github.com/pydantic/pydantic/issues/4535, https://github.com/HypothesisWorks/hypothesis/issues/3703

CPE_VENDOR=	pydantic_project

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pydantic/*${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

PORTNAME=	mando
DISTVERSION=	0.8.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create Python CLI apps with little to no effort at all
WWW=		https://mando.readthedocs.org/ \
		https://github.com/rubik/mando

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest mando/tests/ -v

# tests as of 0.8.2: 83 passed in 2.23s

.include <bsd.port.mk>

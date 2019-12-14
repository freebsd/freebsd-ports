# $FreeBSD$

PORTNAME=	intbitset
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0-9
DISTVERSIONSUFFIX=	-g9513715
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	C-based extension implementing fast integer bit sets

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	inveniosoftware
USE_PYTHON=	cython distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/intbitset.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>

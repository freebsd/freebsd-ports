# $FreeBSD$

PORTNAME=	archinfo
DISTVERSION=	8.20.1.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Classes with architecture-specific information useful to other projects

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	nodefault
GH_TUPLE=	angr:${PORTNAME}:fa979436bd07b4178877d31a5166d28063a89807:tests
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

pre-test:
	@${LN} -Fs ${WRKSRC_tests}/tests ${WRKSRC}/tests

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include <bsd.port.mk>

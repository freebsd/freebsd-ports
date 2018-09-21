# $FreeBSD$

PORTNAME=	pytest-helpers-namespace
PORTVERSION=	2017.11.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Provide a helpers namespace in pytest

LICENSE=	APACHE20

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# pypi tarball does not contain any of the test code?

#do-test:
#	@cd ${WRKSRC} && ${LOCALBASE}/bin/pytest-${PYTHON_VER} tests

.include <bsd.port.mk>

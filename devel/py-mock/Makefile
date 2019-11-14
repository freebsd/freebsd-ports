# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	mock
PORTVERSION=	3.0.5
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mock unit tests for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	testing-cabal

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}funcsigs>=0:devel/py-funcsigs@${PY_FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && pytest

.include <bsd.port.post.mk>

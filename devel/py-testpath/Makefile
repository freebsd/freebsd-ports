# $FreeBSD$

PORTNAME=	testpath
PORTVERSION=	0.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Test utilities for Python code working with files and commands 

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest

USE_GITHUB=	yes
GH_ACCOUNT=	jupyter

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib>=0:devel/py-pathlib
.endif

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER})

.include <bsd.port.post.mk>

PORTNAME=	unicorn
PORTVERSION=	2.0.1p1
CATEGORIES=	emulators python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for Unicorn CPU emulator framework
WWW=		https://www.unicorn-engine.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libunicorn.so:emulators/unicorn
RUN_DEPENDS=	${LOCALBASE}/lib/libunicorn.so:emulators/unicorn

USE_GITHUB=	yes
GH_ACCOUNT=	unicorn-engine
GH_TAGNAME=	2.0.1.post1

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
WRKSRC_SUBDIR=	bindings/python

do-test:
	@(cd ${WRKSRC}; for sample in sample_*.py; do \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} $${sample}; \
	done)

.include <bsd.port.mk>

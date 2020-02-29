# $FreeBSD$

PORTNAME=	unicorn
DISTVERSION=	1.0.2-rc2
CATEGORIES=	emulators python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for Unicorn CPU emulator framework

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libunicorn.so:emulators/unicorn

USE_GITHUB=	yes
GH_ACCOUNT=	unicorn-engine

USES=		python
USE_PYTHON=	distutils autoplist
WRKSRC_SUBDIR=	bindings/python

do-test:
	@(cd ${WRKSRC}; for sample in sample_*.py; do \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} $${sample}; \
	done)

.include <bsd.port.mk>

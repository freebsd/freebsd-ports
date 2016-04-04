# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	biplist
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Library for reading/writing binary plists

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six
TEST_DEPENDS:=	${RUN_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>

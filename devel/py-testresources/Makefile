# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	testresources
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PyUnit extension for managing expensive test resources

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.3:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fixtures>=0:devel/py-fixtures@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=0:devel/py-testtools@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>

# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	testscenarios
PORTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PyUnit extension for dependency injection

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.11:devel/py-pbr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=0:devel/py-testtools@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>

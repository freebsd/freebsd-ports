# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fixtures
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fixtures, reusable state for writing clean tests and more

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.11:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.11:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=0.9.22:devel/py-testtools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

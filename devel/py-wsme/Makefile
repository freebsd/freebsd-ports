# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	wsme
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSME-${PORTVERSION}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Simplify the writing of REST APIs

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplegeneric>=0:devel/py-simplegeneric@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.12:net/py-netaddr@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	XStatic-jquery-ui
PORTVERSION=	1.12.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Jquery-ui 1.12.0 (xstatic packaging standard)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}XStatic>=0:devel/py-XStatic
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

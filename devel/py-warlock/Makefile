# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	warlock
PORTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Python object model built on JSON schema and JSON patch

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=0.7:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>=0.10:devel/py-jsonpatch \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

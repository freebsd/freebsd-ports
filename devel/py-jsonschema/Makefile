# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonschema
PORTVERSION=	2.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	JSON Schema validation for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcversioner>0:devel/py-vcversioner@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == "2.7"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}functools32>0:devel/py-functools32@${FLAVOR}
.endif

.include <bsd.port.post.mk>

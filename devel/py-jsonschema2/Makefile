# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonschema
PORTVERSION=	2.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Schema validation for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcversioner>=2.16.0.0:devel/py-vcversioner@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == "2.7"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}functools32>=0:devel/py-functools32@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>

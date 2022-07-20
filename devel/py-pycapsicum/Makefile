PORTNAME=	pycapsicum
PORTVERSION=	1.0
CATEGORIES=	devel security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/stillson/pycapsicum2/commit/
PATCHFILES+=	5e9854f13448.patch:-p1 # https://github.com/stillson/pycapsicum2/pull/3

MAINTAINER=	stillson@gmail.com
COMMENT=	Python interface to capsicum security

LICENSE=	BSD3CLAUSE

USES=		python:3.6+
USE_CSTD=	c99
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

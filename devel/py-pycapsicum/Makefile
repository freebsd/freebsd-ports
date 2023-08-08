PORTNAME=	pycapsicum
PORTVERSION=	1.0
CATEGORIES=	devel security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/stillson/pycapsicum2/commit/
PATCHFILES+=	5e9854f13448.patch:-p1 # https://github.com/stillson/pycapsicum2/pull/3

MAINTAINER=	stillson@gmail.com
COMMENT=	Python interface to capsicum security
WWW=		https://github.com/stillson/pycapsicum2

LICENSE=	BSD3CLAUSE

USES=		python
USE_CSTD=	c99
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

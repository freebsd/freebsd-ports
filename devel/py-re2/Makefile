# Created by: Edward Chuang <edwardchuang@gmail.com>
# $FreeBSD$

PORTNAME=	re2
PORTVERSION=	0.2.22
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	edwardchuang@gmail.com
COMMENT=	Python wrapper for Google RE2 using Cython

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS=	libre2.so:devel/re2

USES=		python:-2.7
USE_PYTHON=	autoplist distutils
PYDISTUTILS_BUILDARGS=	--cython
EXTRACT_AFTER_ARGS=	--exclude src/re2.cpp

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

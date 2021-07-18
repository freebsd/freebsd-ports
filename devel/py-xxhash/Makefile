PORTNAME=	xxhash
PORTVERSION=	2.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for the xxHash library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxhash>=0.8.0:devel/xxhash
LIB_DEPENDS=	libxxhash.so:devel/xxhash

USES=		localbase python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFIGURE_ENV=	XXHASH_LINK_SO=yes
MAKE_ENV=	XXHASH_LINK_SO=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/xxhash/_xxhash*.so

.include <bsd.port.mk>

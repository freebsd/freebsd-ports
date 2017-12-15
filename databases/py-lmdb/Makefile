# Created by: Keith Gaughan <k@sterechro.me>
# $FreeBSD$

PORTNAME=	lmdb
PORTVERSION=	0.93
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	k@stereochro.me
COMMENT=	Python bindings for LMDB

LICENSE=	OPENLDAP
LICENSE_NAME=	OpenLDAP Public LIcense
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0.8:devel/py-cffi@${FLAVOR}
LIB_DEPENDS=	liblmdb.so:databases/lmdb

USES=		localbase python
USE_PYTHON=	autoplist distutils

MAKE_ENV=	LMDB_FORCE_SYSTEM=1 \
		LMDB_FORCE_CFFI=1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/lmdb/lmdb_cffi.so

.include <bsd.port.mk>

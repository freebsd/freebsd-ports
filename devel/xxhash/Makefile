# $FreeBSD$

PORTNAME=	xxhash
PORTVERSION=	0.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	Extremely fast non-cryptographic hash algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973
GH_PROJECT=	xxHash

USES=		cmake
USE_LDCONFIG=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/cmake_unofficial

PLIST_FILES=	include/xxhash.h \
		lib/libxxhash.so \
		lib/libxxhash.so.0 \
		lib/libxxhash.so.0.42.0

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	folly
DISTVERSIONPREFIX=	v
DISTVERSION=	2019.06.10.00
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	2461dea6d517515ebea623d162722910ede5e86f.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library developed and used at Facebook

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: use of undeclared identifier 'DCHECK': https://github.com/facebook/folly/issues/1168

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

CXXFLAGS+=	-fPIC

.include <bsd.port.mk>

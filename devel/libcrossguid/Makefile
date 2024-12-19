PORTNAME=	libcrossguid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2-52
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gca1bf4b
PORTEPOCH=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/jhaws1982/crossguid/commit/
PATCHFILES=	23a8c007a668413c2e8cbd00984d223ed5ecfe05.patch:-p1

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	Minimal and cross platform C++ GUID library
WWW=		https://github.com/graeme-hill/crossguid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuuid.so:misc/libuuid

USES=		cmake compiler:c++17-lang pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	graeme-hill
GH_PROJECT=	crossguid

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>

# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smack
PORTVERSION=	0.5.0
PORTREVISION=	13
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Low-level I/O storage library which packs data

LICENSE=	GPLv2

BROKEN_powerpc64=	fails to build: libboost_filesystem.so: undefined reference to std::__cxx11::basic_string

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libsnappy.so:archivers/snappy

USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_TAGNAME=	72c81bf

USES=		cmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
CMAKE_ARGS=	-DENABLE_EXAMPLES=ON
.else
CMAKE_ARGS=	-DENABLE_EXAMPLES=OFF
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.include <bsd.port.mk>

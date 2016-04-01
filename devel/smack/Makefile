# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smack
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Low-level I/O storage library which packs data

LICENSE=	GPLv2

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
PLIST_SUB=	EXAMPLES=""
CMAKE_ARGS=	-DENABLE_EXAMPLES=ON
.else
CMAKE_ARGS=	-DENABLE_EXAMPLES=OFF
PLIST_SUB=	EXAMPLES="@comment "
.endif

.include <bsd.port.mk>

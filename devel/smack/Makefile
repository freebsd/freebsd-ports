# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smack
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Low-level I/O storage library which packs data

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs \
		libsnappy.so:${PORTSDIR}/archivers/snappy

USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_COMMIT=	72c81bf
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB=	EXAMPLES=""
CMAKE_ARGS=	-DENABLE_EXAMPLES=ON
.else
CMAKE_ARGS=	-DENABLE_EXAMPLES=OFF
PLIST_SUB=	EXAMPLES="@comment "
.endif

.include <bsd.port.mk>

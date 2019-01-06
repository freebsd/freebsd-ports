# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smack
PORTVERSION=	0.5.0
PORTREVISION=	13
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Low-level I/O storage library which packs data

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_TAGNAME=	72c81bf
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

EXAMPLES_CMAKE_BOOL=	ENABLE_EXAMPLES

.include <bsd.port.mk>

# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library For Reading And Writing LAS-Format Data

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgeotiff.so:graphics/libgeotiff

CONFLICTS=	liblas12-1.2*

USES=		cmake compiler:c++11-lang libtool
LDFLAGS+=	-lpthread
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	libLAS
GH_PROJECT=	${GH_ACCOUNT}

.include <bsd.port.mk>

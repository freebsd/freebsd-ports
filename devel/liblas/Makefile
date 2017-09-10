# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas
PORTVERSION=	1.8.1
PORTREVISION=	6
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library For Reading And Writing LAS-Format Data

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgeotiff.so:graphics/libgeotiff

CONFLICTS=	liblas12-1.2*

PORTSCOUT=	skipv:progress-20071229

USES=		cmake compiler:c++11-lang libtool
LDFLAGS+=	-lpthread
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	libLAS
GH_PROJECT=	${GH_ACCOUNT}

BROKEN_aarch64=		fails to compile: file liblas/detail/endian.hpp needs to be set up for your CPU type
BROKEN_armv6=		fails to compile: file liblas/detail/endian.hpp needs to be set up for your CPU type
BROKEN_powerpc64=	fails to compile: undefined reference to boost::program_options::to_internal

.include <bsd.port.mk>

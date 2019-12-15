# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	liberasurecode
PORTVERSION=	1.4.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unified Erasure Coding interface for common storage workloads

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openstack

USES=		gmake pkgconfig autoreconf libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--disable-werror

TEST_TARGET=	test

.include <bsd.port.mk>

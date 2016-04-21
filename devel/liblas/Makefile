# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas
PORTVERSION=	1.8.0
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library For Reading And Writing LAS-Format Data

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

CONFLICTS=	liblas12-1.2*

USES=		cmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	libLAS
GH_PROJECT=	${GH_ACCOUNT}

.include <bsd.port.mk>

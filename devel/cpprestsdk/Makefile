# $FreeBSD$

PORTNAME=	cpprestsdk
PORTVERSION=	2.9.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	projects@phess.net
COMMENT=	Microsoft C++ REST SDK

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../license.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++11"

USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft

USES=		cmake ssl
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	Release

.include <bsd.port.mk>

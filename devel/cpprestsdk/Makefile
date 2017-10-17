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

USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft

USES=		cmake compiler:c++11-lib ssl
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	Release

.include <bsd.port.mk>

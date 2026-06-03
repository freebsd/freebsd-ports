PORTNAME=	odbc-cpp-wrapper
PORTVERSION=	1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented C++-wrapper of the ODBC API
WWW=		https://github.com/SAP/odbc-cpp-wrapper

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libodbc.so:databases/unixODBC
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++11-lang localbase

CMAKE_ON=	BUILD_SHARED_LIBS

USE_GITHUB=	yes
GH_ACCOUNT=	SAP

.include <bsd.port.mk>

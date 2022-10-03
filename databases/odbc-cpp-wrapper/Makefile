PORTNAME=	odbc-cpp-wrapper
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented C++-wrapper of the ODBC API
WWW=		https://github.com/SAP/odbc-cpp-wrapper

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	SAP

.include <bsd.port.mk>

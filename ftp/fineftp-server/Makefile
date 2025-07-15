PORTNAME=	fineftp-server
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	ftp

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ minimal FTP server library
WWW=		https://github.com/eclipse-ecal/fineftp-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asio>0:net/asio
RUN_DEPENDS=	asio>0:net/asio

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eclipse-ecal

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FINEFTP_SERVER_BUILD_SAMPLES
CMAKE_ARGS=	-Dasio_INCLUDE_DIR=${LOCALBASE}/include

.include <bsd.port.mk>

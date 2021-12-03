PORTNAME=	fineftp-server
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	ftp

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ minimal FTP server library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asio>0:net/asio
RUN_DEPENDS=	asio>0:net/asio

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	continental

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-Dasio_INCLUDE_DIR=${LOCALBASE}/include

.include <bsd.port.mk>

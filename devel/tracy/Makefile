PORTNAME=	tracy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Frame and sampling profiler for games and other applications
WWW=		https://github.com/wolfpld/tracy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	wolfpld

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>

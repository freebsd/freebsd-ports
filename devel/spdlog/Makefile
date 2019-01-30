# Created by: vanilla@
# $FreeBSD$

PORTNAME=	spdlog
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Super fast C++ logging library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lib pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	gabime
CMAKE_ARGS=	-DSPDLOG_BUILD_BENCH=off

.include <bsd.port.mk>

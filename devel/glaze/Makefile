PORTNAME=	glaze
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.5
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, in memory, JSON and interface library for modern C++
WWW=		https://github.com/stephenberry/glaze

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	stephenberry

CMAKE_OFF=	BUILD_TESTING # tests fail to run due to https://github.com/stephenberry/glaze/issues/619

NO_ARCH=	yes

.include <bsd.port.mk>

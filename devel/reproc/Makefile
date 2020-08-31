# $FreeBSD$

PORTNAME=	reproc
DISTVERSIONPREFIX=	v
DISTVERSION=	14.1.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C/C++ library to simplify running external programs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	DaanDeMeyer
USE_LDCONFIG=	yes

CMAKE_ON=	REPROC++ BUILD_SHARED_LIBS

.include <bsd.port.mk>

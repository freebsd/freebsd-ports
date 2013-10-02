# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	6.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	commoncpp

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Very lightweight C++ design pattern library

LICENSE=	LGPL3

USES=		pathfix pkgconfig cmake:outsource
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=ON \
    		-DINSTALL_BINDIR:STRING=bin/${PORTNAME}
USE_LDCONFIG=	yes

regression-test: build
	cd ${BUILD_WRKSRC}/test && ${MAKE} test

.include <bsd.port.mk>

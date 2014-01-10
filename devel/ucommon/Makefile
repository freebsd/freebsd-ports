# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	6.1.0
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

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/ucommon-config.h ${STAGEDIR}${PREFIX}/include/ucommon

regression-test: build
	cd ${BUILD_WRKSRC}/test && ${MAKE} test

.include <bsd.port.mk>

# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	6.1.11
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU/commoncpp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very lightweight C++ design pattern library

LICENSE=	LGPL3

USES=		pathfix pkgconfig cmake:outsource
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=ON \
    		-DINSTALL_BINDIR:STRING=bin/${PORTNAME}
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/ucommon-config.h ${STAGEDIR}${PREFIX}/include/ucommon

regression-test: build
	cd ${BUILD_WRKSRC}/test && ${MAKE} test

.include <bsd.port.mk>

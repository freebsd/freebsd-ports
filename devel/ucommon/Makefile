# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	7.0.0
CATEGORIES=	devel
MASTER_SITES=	GNU/commoncpp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very lightweight C++ design pattern library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		cmake:outsource pathfix pkgconfig
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=ON \
		-DCMAKE_INSTALL_BINDIR:STRING=bin/${PORTNAME} \
		-DCMAKE_INSTALL_MANDIR:STRING=man
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/ucommon-config.h ${STAGEDIR}${PREFIX}/include/ucommon

regression-test: build
	cd ${BUILD_WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test

.include <bsd.port.mk>

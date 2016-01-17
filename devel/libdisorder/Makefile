# $FreeBSD$

PORTNAME=	libdisorder
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://libdisorder.freshdefense.net/releases/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Simple C library for entropy measurement

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/disorder.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libdisorder.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libdisorder.so \
		${STAGEDIR}${PREFIX}/lib/libdisorder.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/tool/ropy ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/lib/libdisorder.so.1 ${STAGEDIR}${PREFIX}/lib/libdisorder.so

.include <bsd.port.mk>

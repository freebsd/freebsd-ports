# $FreeBSD$

PORTNAME=	libdisorder
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://libdisorder.freshdefense.net/releases/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Simple C library for entropy measurement

LICENSE=	GPLv2

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900027
EXTRA_PATCHES=	${FILESDIR}/extra-patch-disorder.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/src/Makefile

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/disorder.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libdisorder.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libdisorder.so \
		${STAGEDIR}${PREFIX}/lib/libdisorder.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/tool/ropy ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/lib/libdisorder.so.1 ${STAGEDIR}${PREFIX}/lib/libdisorder.so

.include <bsd.port.post.mk>

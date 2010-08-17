# New ports collection makefile for:	libdisorder
# Date created:			17 August 2010
# Whom:				kevlo
#
# $FreeBSD$
#

PORTNAME=	libdisorder
PORTVERSION=	0.0.2
CATEGORIES=	devel
MASTER_SITES=	http://libdisorder.freshdefense.net/releases/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A simple C library for entropy measurement

USE_LDCONFIG=	yes

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/disorder.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libdisorder.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/libdisorder.so \
		${PREFIX}/lib/libdisorder.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/tool/ropy ${PREFIX}/bin

post-install:
	${LN} -sf ${PREFIX}/lib/libdisorder.so.1 ${PREFIX}/lib/libdisorder.so

.include <bsd.port.mk>

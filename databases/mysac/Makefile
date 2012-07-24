# New ports collection makefile for: 	mysac
# Date created:				1 January 2012
# Whom:					Jake Smith <jake@xz.cx>
#
# $FreeBSD$
#

PORTNAME=	mysac
PORTVERSION=	1.1.1
CATEGORIES=	databases
MASTER_SITES=	http://www.arpalert.org/src/ \
		http://xz.cx/downloads/mysac/

MAINTAINER=	jake@xz.cx
COMMENT=	MySAC: MySQL Simple Asynchronous Client

USE_LDCONFIG=	yes
USE_MYSQL=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/lib

PLIST_FILES=	lib/libmysac.so \
		lib/libmysac.so.0 \
		lib/libmysac-static.a \
		include/mysac.h

pre-build:
	${TOUCH} ${WRKSRC}/make.deps

do-install:
	${INSTALL_LIB} ${WRKSRC}/libmysac.so \
		${PREFIX}/lib/libmysac.so
	${LN} -sf ${PREFIX}/lib/libmysac.so \
		${PREFIX}/lib/libmysac.so.0
	${INSTALL_LIB} ${WRKSRC}/libmysac-static.a ${PREFIX}/lib/libmysac-static.a
	${INSTALL_DATA} ${WRKSRC}/mysac.h ${PREFIX}/include/mysac.h

.include <bsd.port.mk>

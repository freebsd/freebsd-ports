# New ports collection makefile for: free-libiberty
# Date created: 	30 October 1999
# Whom:			James Howard <ports@vocito.com>
#
# $FreeBSD$
#

PORTNAME=	freelibiberty
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.vocito.com/downloads/software/libiberty/ \
		ftp://ftp.vocito.com/pub/vocito.com/software/libiberty/
DISTNAME=	libiberty-${PORTVERSION}

MAINTAINER=	ports@vocito.com

INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libiberty.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libiberty.so.1 ${PREFIX}/lib/libiberty.so
	${INSTALL_DATA} ${WRKSRC}/libiberty.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include

.include <bsd.port.mk>

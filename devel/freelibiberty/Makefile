# New ports collection makefile for: free-libiberty
# Date created: 	30 October 1999
# Whom:			James Howard <howardjp@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	freelibiberty
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.wam.umd.edu/pub/howardjp/software/libiberty/ \
		http://www.wam.umd.edu/~howardjp/software/libiberty/ \
		ftp://dragon.ham.muohio.edu/pub/howardjp/software/libiberty/
DISTNAME=	libiberty-${PORTVERSION}

MAINTAINER=	howardjp@wam.umd.edu

INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libiberty.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libiberty.so.1 ${PREFIX}/lib/libiberty.so
	${INSTALL_DATA} ${WRKSRC}/libiberty.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include

.include <bsd.port.mk>

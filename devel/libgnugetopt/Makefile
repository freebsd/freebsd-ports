# New ports collection makefile for:	libgnugetopt
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	libgnugetopt
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES= 	ftp://ftp.freebsd.org/pub/FreeBSD/local-distfiles/obrien/

MAINTAINER=	obrien@FreeBSD.org

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/libgnugetopt.so.1 ${PREFIX}/lib
	@ ${LN} -s ${PREFIX}/lib/libgnugetopt.so.1 ${PREFIX}/lib/libgnugetopt.so
	@ ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:	libgnugetopt
# Version required:			1.1
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	libgnugetopt-1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Code/3502/

MAINTAINER=	andy@icc.surw.chel.su

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/libgnugetopt.so.1 ${PREFIX}/lib
	@ ${LN} -s ${PREFIX}/lib/libgnugetopt.so.1 ${PREFIX}/lib/libgnugetopt.so
	@ ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

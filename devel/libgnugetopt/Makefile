# New ports collection makefile for:	libgnugetopt
# Version required:			1.0
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	libgnugetopt-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Code/3502/

MAINTAINER=	andy@icc.surw.chel.su

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/libgnugetopt.a ${PREFIX}/lib

.include <bsd.port.mk>

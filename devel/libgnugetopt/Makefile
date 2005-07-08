# ex:ts=8
# New ports collection makefile for:	libgnugetopt
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

#	Note that GCC contains the master copy of GNU's getopt in libiberty/
#	and include/.  The next time this port is updated, it should use
#	the latest GCC release (the smaller -core dist is fine) for the
#	distfile.	-- David O'Brien <obrien@FreeBSD.org>

PORTNAME=	libgnugetopt
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU getopt library

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/getopt.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/libgnugetopt.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/libgnugetopt.so.1 ${PREFIX}/lib
	@ cd ${PREFIX}/lib ; ${LN} -sf libgnugetopt.so.1 libgnugetopt.so

.include <bsd.port.mk>

# New ports collection makefile for:	Doug Lea malloc library
# Version required:	2.5.3b
# Date created:		3 June 1995
# Whom:			roberto
#
# $Id: Makefile,v 1.5 1997/04/21 00:30:27 obrien Exp $
#

DISTNAME=	dlmalloc
PKGNAME=	dlmalloc-2.6.4
CATEGORIES=	devel
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/
DISTFILES=	malloc-2.6.4.c

MAINTAINER=	roberto@FreeBSD.ORG

NO_WRKSUBDIR=   yes
NO_CONFIGURE=	yes

do-extract:
	@rm -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}
	${CP} -p ${FILESDIR}/Makefile ${WRKDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

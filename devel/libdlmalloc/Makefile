# New ports collection makefile for:	Doug Lea malloc library
# Version required:	2.5.3b
# Date created:		3 June 1995
# Whom:			roberto
#
# $Id$
#

DISTNAME=	dlmalloc
PKGNAME=	dlmalloc-2.5.3b
CATEGORIES+=	development programming libraries
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/
DISTFILES=	malloc-2.5.3b.c

MAINTAINER=	roberto@FreeBSD.ORG

NO_WRKSUBDIR=   yes
NO_CONFIGURE=	yes

do-extract:
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	cp -p ${DISTDIR}/${DISTFILES} ${WRKDIR}
	cp -p ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	Doug Lea malloc library
# Version required:	2.5.3b
# Date created:		3 June 1995
# Whom:			roberto
#
# $FreeBSD$
#

DISTNAME=	dlmalloc
PKGNAME=	dlmalloc-2.6.5
CATEGORIES=	devel
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/
DISTFILES=	malloc-2.6.5.c

MAINTAINER=	roberto@FreeBSD.org

NO_WRKSUBDIR=   yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}
	${CP} -p ${FILESDIR}/Makefile ${WRKDIR}

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

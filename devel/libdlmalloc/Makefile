# New ports collection makefile for:	Doug Lea malloc library
# Date created:		3 June 1995
# Whom:			roberto
#
# $FreeBSD$
#

PORTNAME=	dlmalloc
PORTVERSION=	2.6.5
CATEGORIES=	devel
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/  \
		ftp://ftp.netsw.org/system/libs/memory/optimize/
DISTFILES=	malloc-2.6.5.c

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	Small, fast malloc library by Doug Lea

NO_WRKSUBDIR=	yes
INSTALLS_SHLIB=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}
	${CP} -p ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>

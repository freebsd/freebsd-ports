# Created by: roberto
# $FreeBSD$

PORTNAME=	dlmalloc
PORTVERSION=	2.8.6
CATEGORIES=	devel
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/ 
DISTFILES=	malloc-${PORTVERSION}.c malloc-${PORTVERSION}.h

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	Small, fast malloc library by Doug Lea

NO_WRKSUBDIR=	yes
USE_LDCONFIG=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
.for f in ${DISTFILES}
	${CP} -p ${DISTDIR}/${f} ${WRKDIR}
.endfor
	${CP} -p ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>

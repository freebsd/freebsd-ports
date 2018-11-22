# Created by: roberto
# $FreeBSD$

PORTNAME=	dlmalloc
PORTVERSION=	2.8.6
CATEGORIES=	devel
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/
DISTFILES=	malloc-${PORTVERSION}.c malloc-${PORTVERSION}.h

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast malloc library by Doug Lea

NO_WRKSUBDIR=	yes
USE_LDCONFIG=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	${CP} -p ${DISTDIR}/${f} ${WRKSRC}
.endfor
	${CP} -p ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>

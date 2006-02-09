# New ports collection makefile for:    iozone
# Date created:         26 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	iozone
PORTVERSION=	3.259
PORTREVISION=	0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tar

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Performance Test of Sequential File I/O

CONFLICTS=	iozone-2.*

WRKSRC=		${WRKDIR}/${DISTNAME}/src/current

MAKEFILE=	makefile
MAKE_ARGS=	freebsd	CFLAGS="${CFLAGS}"
ALL_TARGET=

MAN1=		iozone.1
PLIST_FILES=	bin/iozone

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
OPTIONS=	THREADS "Enable threading (uses pthreads)"	on
.endif

.if defined (WITH_THREADS)
CFLAGS+=	-pthread
MAKE_ENV=	LDFLAGS=-lpthread
.else
CFLAGS+=-DNO_THREADS
.endif

do-install:
	${STRIP_CMD} ${WRKSRC}/iozone
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>

# New ports collection makefile for:    iozone
# Date created:         26 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	iozone
PORTVERSION=	3.326
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tar

MAINTAINER=	chifeng@gmail.com
COMMENT=	Performance Test of Sequential File I/O

CONFLICTS=	iozone-2.*

WRKSRC=		${WRKDIR}/${DISTNAME}/src/current

MAKEFILE=	makefile
MAKE_ARGS=	freebsd	CFLAGS="${CFLAGS}"
ALL_TARGET=

MAN1=		iozone.1
PLIST_FILES=	bin/iozone

OPTIONS=	THREADS "Enable threading (uses pthreads)"	on \
		SSH "Use ssh in distributed measurement"	on

.include <bsd.port.pre.mk>

.if defined (WITH_THREADS)
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV=	LDFLAGS=${PTHREAD_LIBS}
.else
CFLAGS+=-DNO_THREADS
.endif

.if defined (WITH_SSH)
post-patch::
	@${REINPLACE_CMD} -e 's|shell\,\"rsh\"|shell\,\"ssh\"|' ${WRKSRC}/iozone.c
.endif

post-patch::
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/makefile

do-install:
	${STRIP_CMD} ${WRKSRC}/iozone
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>

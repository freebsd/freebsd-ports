# Created by: jmz
# $FreeBSD$

PORTNAME=	iozone
DISTVERSION=	3_491
PORTREVISION=	0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performance Test of Sequential File I/O

USES=		gmake tar

WRKSRC=		${WRKDIR}/${DISTNAME}/src/current

MAKEFILE=	makefile
MAKE_ARGS=	${MAKE_ENV}
ALL_TARGET=	freebsd
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/iozone man/man1/iozone.1.gz

OPTIONS_DEFINE=	SSH THREADS
OPTIONS_DEFAULT=SSH THREADS

SSH_DESC=	Use ssh in distributed measurement
THREADS_DESC=	Enable threading (uses pthreads)

THREADS_LDFLAGS=	-lpthread
THREADS_CFLAGS_OFF=	-DNO_THREADS

post-patch-SSH-on:
	@${REINPLACE_CMD} -e 's|shell\,\"rsh\"|shell\,\"ssh\"|' \
		${WRKSRC}/iozone.c

pre-build:
	@cd ${WRKSRC} && ${GMAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

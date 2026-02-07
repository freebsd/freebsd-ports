PORTNAME=	iozone
DISTVERSION=	3_508
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Performance Test of Sequential File I/O
WWW=		https://www.iozone.org/

LICENSE=	IOZONE
LICENSE_NAME=	Iozone license
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/docs/License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake tar

MAKEFILE=	makefile
MAKE_ARGS=	${MAKE_ENV}
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	freebsd

WRKSRC_SUBDIR=	src/current

PLIST_FILES=	bin/iozone \
		share/man/man1/iozone.1.gz

OPTIONS_DEFINE=		SSH THREADS
OPTIONS_DEFAULT=	SSH THREADS

SSH_DESC=	Use ssh in distributed measurement
THREADS_DESC=	Enable threading (uses pthreads)

THREADS_CFLAGS_OFF=	-DNO_THREADS
THREADS_LDFLAGS=	-lpthread

post-patch-SSH-on:
	@${REINPLACE_CMD} -e 's|shell\,\"rsh\"|shell\,\"ssh\"|' \
		${WRKSRC}/iozone.c

pre-build:
	@cd ${WRKSRC} && ${GMAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

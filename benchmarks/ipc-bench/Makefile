PORTNAME=	ipc-bench
DISTVERSION=	1.0
CATEGORIES=	benchmarks

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Benchmarks for various inter-process-communication (IPC)
WWW=		https://github.com/intel/uintr-ipc-bench

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	goldsborough
GH_PROJECT=	ipc-bench
GH_TAGNAME=	589146a

BINARIES=	domain fifo mmap mq shm signal tcp

OPTIONS_DEFINE=	ZMQ
OPTIONS_SUB=	yes
ZMQ_DESC=	Enable ZeroMQ benches via libzmq${ZMQ_VERSION}
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq${ZMQ_VERSION}
ZMQ_VERSION?=	4

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MZMQ}
BINARIES+=	zeromq
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/source/pipe/pipe ${STAGEDIR}${PREFIX}/bin
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/source/${f}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/source/${f}/${f}-client ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/source/${f}/${f}-server ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>

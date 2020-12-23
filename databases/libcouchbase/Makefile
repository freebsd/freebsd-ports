# $FreeBSD$

PORTNAME=	libcouchbase
PORTVERSION=	2.10.7
CATEGORIES=	databases
MASTER_SITES=	http://packages.couchbase.com/clients/c/

MAINTAINER=	sergey@couchbase.com
COMMENT=	Multithreaded noSQL database (client and library)

LICENSE=	APACHE20

BROKEN_mips64=		fails to link: ld: failed to merge target specific data
BROKEN_riscv64=		fails to build: dt_modtext: libdtrace/common/dt_link.c(947): RISC-V implementation required

LIB_DEPENDS=	libevent.so:devel/libevent \
		libev.so:devel/libev \
		libuv.so:devel/libuv

USES=		cmake perl5 ssl
USE_LDCONFIG=	yes
USE_PERL5=	build run

CMAKE_ARGS=	-DLCB_NO_TESTS=1

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
CMAKE_ARGS+=	-DDTRACE:BOOL=FALSE
.endif

.include <bsd.port.post.mk>

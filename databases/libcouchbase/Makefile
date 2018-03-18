# $FreeBSD$

PORTNAME=	libcouchbase
DISTVERSION=	2.8.0
CATEGORIES=	databases
MASTER_SITES=	http://packages.couchbase.com/clients/c/

MAINTAINER=	sergey@couchbase.com
COMMENT=	Multithreaded noSQL database (client and library)

LICENSE=	APACHE20

BROKEN_aarch64=		fails to link: error adding symbols: File in wrong format
BROKEN_armv6=		fails to build: dt_modtext: libdtrace/common/dt_link.c(820): arm not implemented
BROKEN_armv7=		fails to build: dt_modtext: libdtrace/common/dt_link.c(820): arm not implemented
BROKEN_mips64=		fails to link: ld: failed to merge target specific data

LIB_DEPENDS=	libevent.so:devel/libevent \
		libev.so:devel/libev \
		libuv.so:devel/libuv

USES=		cmake perl5 ssl
USE_LDCONFIG=	yes
USE_PERL5=	build run

CMAKE_ARGS=	-DLCB_NO_TESTS=1

.include <bsd.port.mk>

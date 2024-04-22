PORTNAME=	libcouchbase
PORTVERSION=	3.3.8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/couchbase/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	sergey@couchbase.com
COMMENT=	Multithreaded noSQL database (client and library)
WWW=		https://docs.couchbase.com/c-sdk/current/hello-world/start-using-sdk.html

LICENSE=	APACHE20

BROKEN_mips64=	fails to link: ld: failed to merge target specific data

LIB_DEPENDS=	libev.so:devel/libev \
		libevent.so:devel/libevent \
		libuv.so:devel/libuv

USES=		cmake perl5 ssl
USE_LDCONFIG=	yes
USE_PERL5=	build run

CMAKE_ARGS=	-DLCB_NO_TESTS=1

CONFLICTS_INSTALL=	coin-or-cbc

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH:Marmv*} || ${ARCH} == riscv64
CMAKE_ARGS+=	-DDTRACE:BOOL=FALSE
.endif

.include <bsd.port.post.mk>

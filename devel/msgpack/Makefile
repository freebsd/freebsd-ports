# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	1.4.2
PORTREVISION=	1
DISTVERSIONPREFIX=	cpp-
CATEGORIES=	devel

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	MessagePack implementation for C and C++

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_PROJECT=	msgpack-c

USES=		libtool:build autoreconf:build pathfix

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
# required for __sync _* atomic operations on sparc
USE_GCC=	yes
.endif

.if ${ARCH} == "i386"
# Mayby not working on i386/i486/i586...
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} -march=i686" CXXFLAGS="${CXXFLAGS} -march=i686"
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap
post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmsgpackc.so.2.0.0

.include <bsd.port.post.mk>

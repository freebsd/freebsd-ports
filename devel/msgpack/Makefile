# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	cpp-
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	MessagePack implementation for C and C++

LICENSE=	APACHE20

TEST_DEPENDS=	googletest>0:devel/googletest

USE_GITHUB=	yes
GH_PROJECT=	msgpack-c

USES=		autoreconf:build libtool:build localbase pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
# required for __sync _* atomic operations on sparc
USE_GCC=	yes
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>

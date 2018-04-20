# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wrk
PORTVERSION=	4.1.0
CATEGORIES=	benchmarks www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modern HTTP benchmarking tool

LICENSE=	APACHE20

LIB_DEPENDS=	libluajit-5.1.so:lang/luajit

USE_GITHUB=	yes
GH_ACCOUNT=	wg

USES=		gmake ssl
LLD_UNSAFE=	yes
CFLAGS+=	-std=c99 -D_DECLARE_C99_LDBL_MATH -I/${LOCALBASE}/include/luajit-2.0
MAKE_ENV+=	WITH_OPENSSL=${OPENSSLBASE} WITH_LUAJIT=${LOCALBASE} VER=${PORTVERSION}

PLIST_FILES=	bin/wrk

.include <bsd.port.pre.mk>

# Port requires 64 bit atomics
.if ${ARCH} == i386 && empty(MACHINE_CPU:Mi586)
CFLAGS+=	-march=i586
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>

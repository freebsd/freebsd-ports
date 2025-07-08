PORTNAME=	wrk
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	benchmarks www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modern HTTP benchmarking tool
WWW=		https://github.com/wg/wrk

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	wg

FLAVORS=	luajit luajitor
FLAVOR?=	${FLAVORS:[1]}

luajit_PKGNAMESUFFIX=	-luajit
luajitor_PKGNAMESUFFIX=	-luajit-openresty

luajit_CONFLICTS_INSTALL=	${PORTNAME}-luajit-openresty
luajitor_CONFLICTS_INSTALL=	${PORTNAME}-luajit

USES=		gmake ssl
USE_CSTD=	c99
LLD_UNSAFE=	yes
.if ${FLAVOR} == luajit
CFLAGS+=	-I${LOCALBASE}/include/luajit-2.1
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-devel
.else
CFLAGS+=	-I${LOCALBASE}/include/luajit-2.1
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
.endif

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

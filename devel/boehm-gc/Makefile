# New ports collection makefile for:	boehm-gc
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $FreeBSD$
#

PORTNAME=	boehm-gc
PORTVERSION=	6.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTNAME=	gc${PORTVERSION:S/.a/alpha/}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Garbage collection and memory leak detection for C and C++

USE_LIBTOOL_VER=	13
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-cplusplus
OPTIONS=	REDIRECT "Define malloc(3)-family replacements" no \
		FULLDEBUG "full-debug support (see documentation)" no \
		THREADING "POSIX thread support" no \
		PARALLEL_MARK "Parallel-thread marking (faster for SMP)" yes

.include <bsd.port.pre.mk>

.ifdef WITH_THREADING
CONFIGURE_ARGS+=	--enable-threads=posix --enable-thread-local-alloc
.ifdef WITH_PARALLEL_MARK
CONFIGURE_ARGS+=	--enable-parallel-mark
.endif
PKGNAMESUFFIX=	+threaded
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
.ifdef WITH_REDIRECT
CONFIGURE_ARGS+=	--enable-redirect-malloc
PKGNAMESUFFIX:=${PKGNAMESUFFIX}+redirect
.endif
.ifdef WITH_FULLDEBUG
CONFIGURE_ARGS+=	--enable-full-debug
PKGNAMESUFFIX:=${PKGNAMESUFFIX}+fulldebug
.endif

MAN3=		gc.3

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386 and !alpha and !amd64"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/gc.man

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

.include <bsd.port.post.mk>

# New ports collection makefile for:	boehm-gc
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $FreeBSD$
#

PORTNAME=	boehm-gc
PORTVERSION=	6.4
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTNAME=	gc${PORTVERSION:S/.a/alpha/}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Garbage collection and memory leak detection for C and C++

USE_INC_LIBTOOL_VER=	13
USE_GNOME=	lthack
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-cplusplus
OPTIONS=	REDIRECT "Define malloc(3)-family replacements" off \
		FULLDEBUG "full-debug support (see documentation)" off \
		THREADING "POSIX thread support" off \
		PARALLEL_MARK "Parallel-thread marking (faster for SMP)" off

.include <bsd.port.pre.mk>

.if defined(WITH_THREADING) && !defined(WITHOUT_THREADING)
CONFIGURE_ARGS+=	--enable-threads=posix --enable-thread-local-alloc
.if defined(WITH_PARALLEL_MARK) && !defined(WITHOUT_PARALLEL_MARK)
CONFIGURE_ARGS+=	--enable-parallel-mark
.endif
PKGNAMESUFFIX=		+threaded
.else
CONFIGURE_ARGS+=	--disable-threads
PKGNAMESUFFIX=		# empty
.endif
.if defined(WITH_REDIRECT) && !defined(WITHOUT_REDIRECT)
CONFIGURE_ARGS+=	--enable-redirect-malloc
PKGNAMESUFFIX:=		${PKGNAMESUFFIX}+redirect
.endif
.if defined(WITH_FULLDEBUG) && !defined(WITHOUT_FULLDEBUG)
CONFIGURE_ARGS+=	--enable-full-debug
PKGNAMESUFFIX:=		${PKGNAMESUFFIX}+fulldebug
.endif

MAN3=		gc.3

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64" && ${ARCH} != "sparc64" && ${ARCH} != "powerpc"
BROKEN=		"Does not compile on !i386 and !alpha and !amd64 and !sparc64 and !powerpc"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/gc.man

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

.include <bsd.port.post.mk>

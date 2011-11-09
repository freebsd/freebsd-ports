# New ports collection makefile for:	boehm-gc
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $FreeBSD$
#

PORTNAME=	boehm-gc
PORTVERSION=	7.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTNAME=	gc-${PORTVERSION:S/.a/alpha/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Garbage collection and memory leak detection for C and C++

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-cplusplus --disable-static --disable-threads
MAKE_JOBS_UNSAFE=	yes
OPTIONS=	FULLDEBUG "Debugging support (see documentation)" off

.include <bsd.port.pre.mk>

.if defined(WITH_FULLDEBUG)
CONFIGURE_ARGS+=	--enable-gc-debug
PKGNAMESUFFIX:=		${PKGNAMESUFFIX}+fulldebug
.endif

MAN3=		gc.3

.if ${ARCH} == "ia64"
BROKEN=	Does not compile on ia64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/gc.man

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/gc.man ${PREFIX}/man/man3/gc.3

test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>

# New ports collection makefile for:	libhoard
# Date created:			May 24, 2003
# Whom:				Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libhoard
PORTVERSION=	3.6
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.umass.edu/~emery/hoard/hoard-${PORTVERSION}/
DISTNAME=	hoard-36

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast, scalable and memory-efficient allocator for MP

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

ALL_TARGET=	freebsd

PLIST_FILES=	lib/libhoard.so lib/libhoard.so.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501100
IGNORE=		you must have a FreeBSD 5.1-RELEASE or better
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libhoard.so ${PREFIX}/lib/libhoard.so.1
	${LN} -sf ${PREFIX}/lib/libhoard.so.1 ${PREFIX}/lib/libhoard.so

.include <bsd.port.post.mk>

# New ports collection makefile for:	libhoard
# Date created:			May 24, 2003
# Whom:				Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libhoard
PORTVERSION=	3.8
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.umass.edu/~emery/hoard/hoard-${PORTVERSION}/source/
DISTNAME=	hoard-38

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast, scalable and memory-efficient allocator for MP

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

ALL_TARGET=	freebsd

PLIST_FILES=	lib/libhoard.so lib/libhoard.so.1

post-patch:
	${REINPLACE_CMD} 's!g++!${CXX}!; s!-O2!${CFLAGS}!' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libhoard.so ${PREFIX}/lib/libhoard.so.1
	${LN} -sf ${PREFIX}/lib/libhoard.so.1 ${PREFIX}/lib/libhoard.so

.include <bsd.port.mk>

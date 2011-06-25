# New ports collection makefile for:	squish
# Date created:		08 Mar 2011
# Whom:			Reinier de Blois <me@rdb.name>
#
# $FreeBSD$
#

PORTNAME=	squish
PORTVERSION=	1.10
CATEGORIES=	graphics
MASTER_SITES=	http://libsquish.googlecode.com/files/

MAINTAINER=	me@rdb.name
COMMENT=	Open source DXT compression library

LICENSE=	MIT
USE_GMAKE=	YES
PLIST_FILES=	include/squish.h \
		lib/libsquish.a
OPTIONS=	ALTIVEC "Use Altivec instructions" off \
		SSE "Use SSE2 instructions" off

.include <bsd.port.options.mk>

.if defined(WITH_ALTIVEC) && defined(WITH_SSE)
IGNORE=		cannot build with both WITH_ALTIVEC and WITH_SSE
.endif

CXXFLAGS+=	-fPIC

.if defined(WITH_ALTIVEC)
CXXFLAGS+=	-DSQUISH_USE_ALTIVEC=1 -maltivec
.endif

.if defined(WITH_SSE)
CXXFLAGS+=	-DSQUISH_USE_SSE=2 -msse
.endif

.include <bsd.port.mk>

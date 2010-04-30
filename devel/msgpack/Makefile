# New ports collection makefile for:	msgpack
# Date created:		18 Jan 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	msgpack
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	msgpack/msgpack/cpp

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Binary-based efficient data interchange format focused on performance

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
# required for __sync _* atomic operations on sparc
USE_GCC=	4.4+
.else
USE_GCC=	4.2+
.endif

.if ${ARCH} == "i386"
# Mayby not working on i386/i486/i586...
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} -march=i686" CXXFLAGS="${CXXFLAGS} -march=i686"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	cxxtools
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cxxtools
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Collection of general-purpose C++ classes

PATCH_STRIP=	-p1
USE_ICONV=	yes
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

.include <bsd.port.post.mk>

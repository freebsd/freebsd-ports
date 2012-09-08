# New ports collection makefile for:	csmith
# Date created:				2011-10-25
# Whom:					Eitan Adler <eadler@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	csmith
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/csmith/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Generates random C programs that conform to the C99 standard

LICENSE=	BSD

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64 (includes i386 asm)
.endif

.include <bsd.port.post.mk>

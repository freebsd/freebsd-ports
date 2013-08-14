# New ports collection makefile for:	libjit
# Date created:		2004-04-27
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libjit
PORTVERSION=	0.1.2
CATEGORIES=	lang
MASTER_SITES=	SAVANNAH/dotgnu-pnet/libjit-releases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libjit implements Just-In-Time compilation functionality

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=	pathfix
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CFLAGS+=	-O0

INFO=		libjit
MAN3=		libjit.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Segfault during build
.elif ${ARCH} == "powerpc"
BROKEN=		Fails to compile: invokes i386 asm
.elif ${ARCH} == "sparc64"
BROKEN=		Fails to compile: internal gcc error
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#undef HAVE_TGMATH_H||' \
		${WRKSRC}/config.h.in

.include <bsd.port.post.mk>

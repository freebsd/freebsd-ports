# New ports collection makefile for:    jikes
# Date created:         09 December 1998
# Whom:                 Matthew Dillon <dillon@backplane.com>
#
# $FreeBSD$
#

PORTNAME=	jikes
PORTVERSION=	1.22
CATEGORIES=	java
MASTER_SITES=	ftp://www-126.ibm.com/pub/jikes/${PORTVERSION}/

MAINTAINER=	archie@freebsd.org
COMMENT=	A very fast Java source to byte-code compiler made available by IBM

MAN1=		jikes.1

PLIST_SUB=	PORTVERSION=${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_BZIP2=	yes

CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Internal compiler error on alpha 4.x"
.endif

.include <bsd.port.post.mk>

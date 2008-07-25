#
# New ports collection makefile for:	xrally
# Date created:				86 May 2005
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	xrally
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/xrally
DISTNAME=	${PORTNAME}-1.1

MAINTAINER=	edwin@mavetju.org
COMMENT=	XRally is a Linux clone of the classic Rally X arcade game

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GCC=	2.95
PTHREAD_LIBS=	-lc_r
HAS_CONFIGURE=	yes
USE_XORG=	x11 xi xpm
USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS}"
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		INCLUDES="-I${LOCALBASE}/include"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
BROKEN=		Doesn't work (yet?) on 7.x
.endif

.include <bsd.port.post.mk>

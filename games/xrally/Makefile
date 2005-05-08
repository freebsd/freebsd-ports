#
# New ports collection makefile for:	xrally
# Date created:				86 May 2005
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	xrally
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xrally

MAINTAINER=	edwin@mavetju.org
COMMENT=	XRally is a Linux clone of the classic Rally X arcade game

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GCC=	2.95
HAS_CONFIGURE=	yes
USE_PTHREADS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include" \
		INCLUDES="-I${X11BASE}/include"

.include <bsd.port.mk>

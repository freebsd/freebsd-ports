# New ports collection makefile for:	tome
# Date created:		04 Nov 2002
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tome
PORTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
DISTNAME=	tome-225-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Roguelike dungeon exploration game based on JRR Tolkien's works

ALL_TARGET=	# empty
MAKEFILE=	makefile.std
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

.if exists(${X11BASE}/lib/libX11.a) && !defined(WITHOUT_X11)
USE_XLIB=      yes
.endif

post-patch:
.if !defined(USE_XLIB)
	${REINPLACE_CMD} -e 's/-DUSE_X11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's/-lX11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-L$$(X11BASE)/lib@@g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-I$$(X11BASE)/include@@g' ${WRKSRC}/${MAKEFILE}
.endif


.include <bsd.port.mk>

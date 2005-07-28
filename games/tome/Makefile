# New ports collection makefile for:	tome
# Date created:		04 Nov 2002
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tome
PORTVERSION=	2.3.2
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
DISTNAME=	tome-232-src

MAINTAINER=	eol1@yahoo.com
COMMENT=	Roguelike dungeon exploration game based on JRR Tolkien's works

ALL_TARGET=	# empty
MAKEFILE=	makefile.bsd
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/lib/libX11.a) && !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

post-patch:
.if !defined(USE_XLIB)
	${REINPLACE_CMD} -e 's/-DUSE_X11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's/-lX11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-L$$(X11BASE)/lib@@g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-I$$(X11BASE)/include@@g' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>

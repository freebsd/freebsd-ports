# New ports collection makefile for:	tome
# Date created:		04 Nov 2002
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tome
PORTVERSION=	2.3.3
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
DISTNAME=	tome-233-src

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	Roguelike dungeon exploration game based on JRR Tolkien's works

ALL_TARGET=	# empty
MAKEFILE=	makefile.bsd
USE_GMAKE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS=		X11 "Turn on support for X" on
DESKTOP_ENTRIES=	"ToME" "Roguelike game based on JRR Tolkien's work" \
			"${DATADIR}/xtra/graf/tome-128.png" \
			"tome -v -g" "Application;Game;RolePlaying;" \
			false

.include <bsd.port.pre.mk>

.ifndef (WITHOUT_X11)
USE_XLIB=	yes
.endif

post-patch:
.ifdef (WITHOUT_X11)
	${REINPLACE_CMD} -e 's/-DUSE_X11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's/-lX11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-L$$(X11BASE)/lib@@g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-I$$(X11BASE)/include@@g' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>

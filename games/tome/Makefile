# New ports collection makefile for:	tome
# Date created:		04 Nov 2002
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tome
PORTVERSION=	2.3.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
DISTNAME=	tome-235-src

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	Roguelike dungeon exploration game based on JRR Tolkien's works

SUB_FILES=	pkg-deinstall

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
USE_XORG=	x11
.endif

post-patch:
.ifdef (WITHOUT_X11)
	${REINPLACE_CMD} -e 's/-DUSE_X11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's/-lX11//g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-L$$(LOCALBASE)/lib@@g' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's@-I$$(LOCALBASE)/include@@g' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.7.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ac-grenoble.fr/Office/
MASTER_SITE_SUBDIR=	sf-${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple paint program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes

MAN1=		xpaint.1

CFLAGS+=	-DARROW_SCROLLBAR

.if defined(WITH_NEXTAW)
LIB_DEPENDS+=	neXtaw.${XAWVER}:${PORTSDIR}/x11-toolkits/neXtaw
ALL_TARGET=	nextaw
XAW_INCDIR=	${X11BASE}/include/X11/neXtaw
.else
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
ALL_TARGET=	xaw3d
XAW_INCDIR=	${X11BASE}/include/X11/Xaw3d
.endif

pre-configure:
	@cd ${WRKSRC} && ${LN} -sf ${XAW_INCDIR} xaw_incdir

.include <bsd.port.mk>

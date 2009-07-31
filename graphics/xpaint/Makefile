# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.7.8.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF \
		ftp://ftp.ac-grenoble.fr/Office/
MASTER_SITE_SUBDIR=	sf-${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple paint program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XORG=	xpm

MAN1=		xpaint.1

.if defined(WITH_NEXTAW)
LIB_DEPENDS+=	neXtaw:${PORTSDIR}/x11-toolkits/neXtaw
XAW_INCDIR=	${LOCALBASE}/include/X11/neXtaw
XAW_LIBS=	-lneXtaw
.else
LIB_DEPENDS+=  Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
XAW_INCDIR=	${LOCALBASE}/include/X11/Xaw3d
XAW_LIBS=	-lXaw3d
.endif

pre-configure:
	@cd ${WRKSRC} && ${LN} -sf ${XAW_INCDIR} xaw_incdir \
		&& ${ECHO_CMD} -n > Local.xawdefs \
		&& ${ECHO_CMD} "XAWLIB_DEFINES=-DXAW3D" >> Local.xawdefs \
		&& ${ECHO_CMD} "SYS_LIBRARIES=${XAW_LIBS}" >> Local.xawdefs

.include <bsd.port.mk>

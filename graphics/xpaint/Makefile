# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.7.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ac-grenoble.fr/Office/
MASTER_SITE_SUBDIR=	sf-${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple paint program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes
ALL_TARGET=	xaw3d

MAN1=		xpaint.1

pre-configure:
	@cd ${WRKSRC} && ${LN} -sf ${X11BASE}/include/X11/Xaw3d xaw_incdir

.include <bsd.port.mk>

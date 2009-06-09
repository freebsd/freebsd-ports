# New ports collection makefile for:    xfpovray
# Date created:         20 Sep 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfpovray
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.batse.msfc.nasa.gov/~mallozzi/home/software/xforms/src/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/rays/pov
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface to POV-Ray

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

USE_IMAKE=	yes
USE_XORG=	x11 xext xpm
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g;" ${WRKSRC}/src/xfpovray.h

.include <bsd.port.mk>

# New ports collection makefile for:    xfpovray
# Version required:     1.2.4
# Date created:         20 Sep 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/01/09 14:39:20 tg Exp $
#

DISTNAME=       xfpovray-1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.batse.msfc.nasa.gov/~mallozzi/software/xfpovray/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	xforms\\.0\\.88:${PORTSDIR}/x11/xforms
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

USE_IMAKE=	yes
USE_GMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@/usr/bin/perl -pi -e "s|@LOCALBASE@|${LOCALBASE}|g;" ${WRKSRC}/src/xfpovray.h

.include <bsd.port.mk>

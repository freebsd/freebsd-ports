# New ports collection makefile for:    xfpovray
# Version required:     1.3.1
# Date created:         20 Sep 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1999/01/07 08:19:39 simokawa Exp $
#

DISTNAME=       xfpovray-1.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.batse.msfc.nasa.gov/~mallozzi/software/xfpovray/v1.3.1/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/rays/pov
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

# depends on xforms
ONLY_FOR_ARCHS=	i386

USE_IMAKE=	yes
USE_GMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@/usr/bin/perl -pi -e "s|@LOCALBASE@|${LOCALBASE}|g;" ${WRKSRC}/src/xfpovray.h

.include <bsd.port.mk>

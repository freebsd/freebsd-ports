# New ports collection makefile for:    xfpovray
# Version required:     1.3.1
# Date created:         20 Sep 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/08/07 23:56:27 asami Exp $
#

DISTNAME=       xfpovray-1.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://crazyhorse.msfc.nasa.gov/~mallors/software/xfpovray/v1.3.1/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/rays/pov
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

BROKEN_ELF=	xforms is a.out only

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

USE_IMAKE=	yes
USE_GMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@/usr/bin/perl -pi -e "s|@LOCALBASE@|${LOCALBASE}|g;" ${WRKSRC}/src/xfpovray.h

.include <bsd.port.mk>

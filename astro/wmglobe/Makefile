# New ports collection makefile for:	wmglobe
# Version required:	1.0
# Date created:		23 Jun 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	wmglobe-1.0
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://perso.linuxfr.org/jdumont/wmg/ \
		http://www.cana.net/~acme/wmglobe/ \
		http://www.psn.net/~andrews/wmglobe/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gif.5:${PORTSDIR}/graphics/giflib \
		wraster.3:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN1=		wmglobe.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmglobe ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wmglobe.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

# New ports collection makefile for: sattrack
# Version required:                  3.1.6
# Date created:                      6 Apr 1996
# Whom:                              Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

DISTNAME=          sattrack-3.1.6
CATEGORIES=        astro
MASTER_SITES=      ${MASTER_SITE_LOCAL}

MAINTAINER=        bjn@visi.com

USE_XLIB=	   yes
WRKSRC=            ${WRKDIR}/SatTrack-3.1.6/src

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

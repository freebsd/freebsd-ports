# New ports collection makefile for: sattrack
# Version required:                  3.1.4
# Date created:                      6 Apr 1996
# Whom:                              Brent J. Nordquist <nordquist@platinum.com>
#
# $Id: Makefile,v 1.3 1996/10/31 11:22:02 asami Exp $
#

DISTNAME=          sattrack-3.1.4
CATEGORIES=        astro
MASTER_SITES=      http://ssl.berkeley.edu/isi_www/

MAINTAINER=        nordquist@platinum.com

# restrictive copyright: distribution via ftp is OK,
# bundling with commercial products (CDROM) is forbidden
# without author's consent
NO_CDROM=	   yes

WRKSRC=            ${WRKDIR}/SatTrack/src
MAKE_FLAGS=        PREFIX=${PREFIX} -f

.include <bsd.port.mk>

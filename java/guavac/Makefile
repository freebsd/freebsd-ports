# New ports collection makefile for:   guavac
# Version required:    0.3.1
# Date created:        10 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1997/06/30 09:43:12 max Exp $
#

DISTNAME=	guavac-0.3.1
CATEGORIES=	lang
MASTER_SITES=	ftp://summit.stanford.edu/pub/guavac/ \
		ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/\
		ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		guavac.1
STRIP=

post-install:
	@strip ${PREFIX}/bin/guavac ${PREFIX}/bin/guavad

.include <bsd.port.mk>

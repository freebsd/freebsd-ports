# New ports collection makefile for:	polygraph
# Version required:	1.0p6
# Date created:         3 March 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $Id: $
#

DISTNAME=	polygraph-1.0p6-src
PKGNAME=	polygraph-1.0p6
CATEGORIES=	benchmarks www
MASTER_SITES=	http://polygraph.ircache.net/sources/	\
		http://www.chg.ru/~dima/

MAINTAINER=	dima@Chg.RU

WRKSRC=		${WRKDIR}/polygraph/src

do-install:

		@ ${INSTALL_PROGRAM} ${WRKSRC}/polyclt ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/polysrv ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/lr ${PREFIX}/bin

.include <bsd.port.mk>

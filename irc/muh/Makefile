# New ports collection makefile for:   muh
# Version required:    2.02
# Date created:        25 Sept 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: $
#

DISTNAME=	muh2.02
PKGNAME=	muh-2.02
CATEGORIES=	net
MASTER_SITES=	http://www.riot.org/releases/misc/

MAINTAINER=	billf@FreeBSD.org

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/muh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/muhrc ${PREFIX}/share/skel/dot.muhrc

.include <bsd.port.mk>

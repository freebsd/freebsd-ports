# New ports collection makefile for:   muh
# Version required:    2.04
# Date created:        25 Sept 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.4 1999/06/28 02:20:46 billf Exp $
#

DISTNAME=	muh2.04
PKGNAME=	muh-2.04
CATEGORIES=	irc
MASTER_SITES=	http://mind.riot.org/download/

MAINTAINER=	billf@FreeBSD.org

BROKEN='md5 checksum mismatch'

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/src/muh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/muhrc ${PREFIX}/share/skel/dot.muhrc

.include <bsd.port.mk>

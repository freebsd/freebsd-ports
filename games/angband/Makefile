# New ports collection makefile for:   angband
# Version required:    2.8.2
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.3 1997/09/19 06:46:36 tg Exp $
#

DISTNAME=	angband-282
PKGNAME=	angband-2.8.2
CATEGORIES=	games
MASTER_SITES=	ftp://export.andrew.cmu.edu/angband/Source/

MAINTAINER=	mph@pobox.com

USE_X11=	yes

post-install:
	@${CAT} ${PKGDIR}/MESSAGE
	@${INSTALL_DATA} ${FILESDIR}/CHANGES-2.8.2 ${PREFIX}/lib/X11/angband

.include <bsd.port.mk>

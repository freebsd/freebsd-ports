# New ports collection makefile for:    cdd
# Version required:     none
# Date created:         Wed Dec 23 11:15:30 CET 1998
# Whom:                 luigi@iet.unipi.it
#
# $Id$
#

DISTNAME=	cdd-1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.iet.unipi.it/~luigi/cdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	luigi@iet.unipi.it

post-extract:
	${cp}cp ${FILESDIR}/cdd_atapicmds.[ch] ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin

.include <bsd.port.mk>

# New ports collection makefile for:	portlint
# Version required:     (self contained)
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.21 1999/01/05 12:23:27 itojun Exp $
#

DISTNAME=       portlint-2.0
CATEGORIES=	devel
DISTFILES=	#empty

MAINTAINER=	itojun@itojun.org

NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_WRKSUBDIR=	yes

SRC=		${.CURDIR}/src

MAN1=		portlint.1

do-fetch:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${SRC}/portlint.pl ${PREFIX}/bin/portlint
	${INSTALL_MAN} ${SRC}/portlint.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

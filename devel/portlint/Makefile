# New ports collection makefile for:	portlint
# Version required:     1.61
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.19 1997/11/25 11:43:15 itojun Exp $
#

DISTNAME=       portlint-1.61
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/portlint/
EXTRACT_SUFX=	.shar

MAINTAINER=	itojun@itojun.org

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=			# yes, it is blank
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

MAN1=		portlint.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portlint.pl ${PREFIX}/bin/portlint
	${INSTALL_MAN} ${WRKDIR}/portlint.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

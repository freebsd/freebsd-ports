# New ports collection makefile for:	portlint
# Version required:     1.43
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.5 1997/07/16 18:49:46 itojun Exp $
#

DISTNAME=       portlint-1.43
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/portlint/
EXTRACT_SUFX=	.shar

MAINTAINER=	itojun@itojun.org

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=			# yes, it is blank
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

MAN1=		portlint.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portlint.pl ${PREFIX}/bin/portlint
	${INSTALL_MAN} ${WRKDIR}/portlint.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

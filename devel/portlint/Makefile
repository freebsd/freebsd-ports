# New ports collection makefile for:	portlint
# Version required:     1.28
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.2 1997/07/06 00:39:00 max Exp $
#

DISTNAME=       portlint.pl-1.28
PKGNAME=        portlint-1.28
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/portlint/
EXTRACT_SUFX=

MAINTAINER=	itojun@itojun.org

EXTRACT_ONLY=			# This value is intentionally left empty.
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/portlint

.include <bsd.port.mk>

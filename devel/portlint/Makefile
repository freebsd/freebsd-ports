# New ports collection makefile for:	portlint
# Version required:     1.9
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id$
#

DISTNAME=       portlint.pl-1.9
PKGNAME=        portlint-1.9
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/tools/portlint/
EXTRACT_SUFX=

MAINTAINER=	itojun@itojun.org

EXTRACT_ONLY=			# This value is intentionally left empty.
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/portlint

.include <bsd.port.mk>

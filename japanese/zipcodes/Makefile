# New ports collection makefile for:	ja-zipcodes
# Version required:	19980130
# Date created:		5 Nov 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.8 1999/01/09 14:45:20 itojun Exp $
#

DISTNAME=	ken_all
PKGNAME=	ja-zipcodes-19980130
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.postal.mpt.go.jp/lzh/ \
		http://freefall.freebsd.org/~itojun/distfiles/
EXTRACT_SUFX=	.lzh

MAINTAINER=	itojun@itojun.org

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}
NO_WRKSUBDIR=	yes

MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR}

.include <bsd.port.mk>

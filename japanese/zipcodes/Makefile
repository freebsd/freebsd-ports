# New ports collection makefile for:	ja-zipcodes
# Version required:	1.0
# Date created:		5 Nov 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id$
#

DISTNAME=	ken_all
PKGNAME=	ja-zipcodes-1.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.postal.mpt.go.jp/lzh/
EXTRACT_SUFX=	.lzh

MAINTAINER=	itojun@itojun.org

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}
NO_WRKSUBDIR=	yes

MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	ja-zipcodes
# Date created:		5 Nov 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	zipcodes
PORTVERSION=	20010325
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.postal.mpt.go.jp/newnumber/lzh/s/
EXTRACT_SUFX=	.lzh
DISTNAME=	ken_all

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	p
EXTRACT_AFTER_ARGS=	>ken_all.csv
NO_WRKSUBDIR=	yes

MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	ja-zipcodes
# Date created:		5 Nov 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	zipcodes
PORTVERSION=	20031108
CATEGORIES=	japanese misc
MASTER_SITES=	http://post.ah-tech.co.jp/zipcode/dl/kogaki/lzh/
DISTNAME=	ken_all
EXTRACT_SUFX=	.lzh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese zipcode tables. includes both 3/5 and 7 digits form

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	p
EXTRACT_AFTER_ARGS=	>ken_all.csv
NO_WRKSUBDIR=	yes

USE_PERL5_BUILD=yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR} PERL=${PERL}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>

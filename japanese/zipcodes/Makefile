# New ports collection makefile for:	ja-zipcodes
# Date created:		5 Nov 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	zipcodes
PORTVERSION=	20020701
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.post.yusei.go.jp/newnumber/lzh/s/
DISTNAME=	ken_all
EXTRACT_SUFX=	.lzh

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	p
EXTRACT_AFTER_ARGS=	>ken_all.csv
NO_WRKSUBDIR=	yes

USE_PERL5=	yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR} PERL=${PERL}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>

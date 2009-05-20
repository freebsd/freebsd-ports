# New ports collection makefile for:	ja-zipcodes
# Date created:		5 Nov 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	zipcodes
PORTVERSION=	20090430
CATEGORIES=	japanese
MASTER_SITES=	http://dist.bsdlab.org/
DISTFILES=	ken_all-${PORTVERSION_K}.lzh jigyosyo-${PORTVERSION_J}.lzh

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Japanese zipcode tables. includes both 3/5 and 7 digits form

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	x
EXTRACT_AFTER_ARGS=
NO_WRKSUBDIR=	yes

USE_PERL5_BUILD=yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR} PERL=${PERL}
PORTVERSION_K?=	${PORTVERSION}
PORTVERSION_J?=	${PORTVERSION}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

# for maintainance.
fetch1:
	fetch http://www.post.japanpost.jp/zipcode/dl/kogaki/lzh/ken_all.lzh
	fetch http://www.post.japanpost.jp/zipcode/dl/jigyosyo/lzh/jigyosyo.lzh
	${CHMOD} og+r *.lzh

fetch2:
	m=`stat -f %m ken_all.lzh`; \
	${MV} ken_all.lzh `date -r $${m} +ken_all-%Y%m%d.lzh`
	m=`stat -f %m jigyosyo.lzh`; \
	${MV} jigyosyo.lzh `date -r $${m} +jigyosyo-%Y%m%d.lzh`

.include <bsd.port.mk>

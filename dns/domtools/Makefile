# New ports collection makefile for:	domtools
# Date created:				12 Jun 1999
# Whom:					alexp
#
# $FreeBSD$
#

PORTNAME=	domtools
PORTVERSION=	1.6.0
CATEGORIES=	dns
MASTER_SITES=	http://www.domtools.com/pub/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://www.sfr-fresh.com/unix/misc/dns/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities for extracting information from DNS records

USE_PERL5=	YES

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/domtools${PORTVERSION}/

MAKE_ENV+=	PDEST=${PREFIX}

# XXX - patches/patch-aa modifies Makefile
# and so does the post-patch target

post-patch:

	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${SED} -e 's#/usr/bin/perl#${PERL5}#' -e '/^PDEST=/d' \
	< ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile

post-install:

	${MKDIR} ${PREFIX}/domtools/lib/zonecache

.include <bsd.port.mk>

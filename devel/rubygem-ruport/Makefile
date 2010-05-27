# New ports collection makefile for:	rubygem-ruport
# Date created:		7 April 2009
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	ruport
PORTVERSION=	1.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	 Ruby Reports (Ruport) is an extensible reporting system.

RUN_DEPENDS=	rubygem-transactionsimple>=1.4.0:${PORTSDIR}/devel/rubygem-transactionsimple \
  				rubygem-fastercsv>=1.1.0:${PORTSDIR}/devel/rubygem-fastercsv \
				rubygem-pdfwriter>=1.1.3:${PORTSDIR}/print/rubygem-pdfwriter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

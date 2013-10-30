# $FreeBSD$

PORTNAME=	ruport
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Reports (Ruport) is an extensible reporting system

RUN_DEPENDS=	rubygem-transactionsimple>=1.4.0:${PORTSDIR}/devel/rubygem-transactionsimple \
  				rubygem-fastercsv>=1.1.0:${PORTSDIR}/devel/rubygem-fastercsv \
				rubygem-pdfwriter>=1.1.3:${PORTSDIR}/print/rubygem-pdfwriter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

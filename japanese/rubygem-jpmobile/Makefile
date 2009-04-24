# New ports collection makefile for:	rubygem-jpmobile
# Date created:		2008-02-06
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	jpmobile
PORTVERSION=	0.0.2
CATEGORIES=	japanese www rubygems
MASTER_SITES=	RF

MAINTAINER=	tota@rtfm.jp
COMMENT=	A Rails plugin for Japanese mobile-phones

BUILD_DEPENDS=	rubygem-actionpack>=1.12.5:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-hpricot>=0.4:${PORTSDIR}/www/rubygem-hpricot
RUN_DEPENDS=	rubygem-actionpack>=1.12.5:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-hpricot>=0.4:${PORTSDIR}/www/rubygem-hpricot

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

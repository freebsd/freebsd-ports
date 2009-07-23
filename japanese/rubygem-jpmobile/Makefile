# New ports collection makefile for:	rubygem-jpmobile
# Date created:		2008-02-06
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	jpmobile
PORTVERSION=	0.0.6
CATEGORIES=	japanese www rubygems
MASTER_SITES=	RF

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A Rails plugin for Japanese mobile-phones

BUILD_DEPENDS=	rubygem-actionpack>=2.3.2:${PORTSDIR}/www/rubygem-actionpack
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

# New ports collection makefile for:	rubygem-gemcutter
# Date created:		21 September 2010
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	gemcutter
PORTVERSION=	0.7.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extensions to RubyGems for managing gems and more on RubyGems.org

RUN_DEPENDS=	rubygem-rr>=0:${PORTSDIR}/devel/rubygem-rr \
  				rubygem-webmock>=0:${PORTSDIR}/www/rubygem-webmock \
				rubygem-activesupport>=0:${PORTSDIR}/devel/rubygem-activesupport \
				rubygem-shoulda>=0:${PORTSDIR}/devel/rubygem-shoulda
USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

# Ports collection makefile for:	rubygem-memchache-client
# Date created:				26 January 2006
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	memcache-client
PORTVERSION=	1.5.0
CATEGORIES=	databases rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	seattlerb

MAINTAINER=	jw@innerewut.de
COMMENT=	Ruby bindings for MemCached

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		rubygem-zentest>=3.4.2:${PORTSDIR}/devel/rubygem-zentest \
		rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

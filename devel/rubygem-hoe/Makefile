# Ports collection makefile for:	rubygem-hoe
# Date created:				5 December 2006
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	hoe
PORTVERSION=	1.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	seattlerb

MAINTAINER=	jw@innerewut.de
COMMENT=	hoe - a tool to help rake

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		rubyforge:${PORTSDIR}/devel/rubygem-rubyforge
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

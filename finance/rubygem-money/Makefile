# Ports collection makefile for:	rubygem-money
# Date created:				27 April 2011
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	money
PORTVERSION=	3.7.0
CATEGORIES=	finance rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Library for handling money and different currencies

RUN_DEPENDS=	rubygem-i18n>=0.4:${PORTSDIR}/devel/rubygem-i18n

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>

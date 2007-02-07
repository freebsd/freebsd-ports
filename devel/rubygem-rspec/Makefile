# Ports collection makefile for:	rubygem-rspec
# Date created:				22 December 2006
# Whom:					Roman Shterenzon <romanbsd@yahoo.com>
#
# $FreeBSD$

PORTNAME=	rspec
PORTVERSION=	0.7.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	rspec

MAINTAINER=	romanbsd@yahoo.com
COMMENT=	Behaviour Driven Development in Ruby

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

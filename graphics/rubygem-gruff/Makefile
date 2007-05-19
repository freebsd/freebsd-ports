# ex:ts=8
# Ports collection makefile for:	rubygem-gruff
# Date created:			Jan 7, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gruff
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A beautiful graphing library for Ruby using RMagick

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/RMagick.so:${PORTSDIR}/graphics/ruby-rmagick \
		sow:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

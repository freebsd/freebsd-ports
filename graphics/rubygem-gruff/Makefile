# ex:ts=8
# Ports collection makefile for:	rubygem-gruff
# Date created:			Jan 7, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gruff
PORTVERSION=	0.2.9
PORTREVISION=	0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A beautiful graphing library for Ruby using RMagick

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/RMagick.so:${PORTSDIR}/graphics/ruby-rmagick \
		sow:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>

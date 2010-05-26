# ex:ts=8
# Ports collection makefile for:	rubygem-gruff
# Date created:			Jan 7, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gruff
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A beautiful graphing library for Ruby using RMagick

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/RMagick2.so:${PORTSDIR}/graphics/ruby-rmagick \
		sow:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

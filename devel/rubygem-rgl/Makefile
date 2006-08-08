# New ports collection makefile for:	devel/rubygem-rgl
# Date created:				02.08.2005
# Whom:					Ulrich Spoerlein <q@galgenberg.net>
#
# $FreeBSD$
#

PORTNAME=	rgl
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Framework for graph datastructures and algorithms implemented in Ruby

RUN_DEPENDS=	${LOCALBASE}/lib/ruby/gems/1.8/specifications/stream-0.5.gemspec:${PORTSDIR}/devel/rubygem-stream

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

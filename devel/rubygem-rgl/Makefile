# New ports collection makefile for:	devel/rubygem-rgl
# Date created:				02.08.2005
# Whom:					Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rgl
PORTVERSION=	0.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Framework for graph datastructures and algorithms implemented in Ruby

RUN_DEPENDS=	${LOCALBASE}/lib/ruby/gems/1.8/specifications/stream-0.5.gemspec:${PORTSDIR}/devel/rubygem-stream

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

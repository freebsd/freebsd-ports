# ex:ts=8
# Ports collection makefile for:	rubygem-scruffy
# Date created:			Jan 7, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scruffy
PORTVERSION=	0.2.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Beautiful Graphs for Ruby

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/builder-2.1.1.gemspec:${PORTSDIR}/devel/rubygem-builder

USE_RUBY=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

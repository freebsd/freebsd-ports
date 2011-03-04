# New ports collection makefile for:	multi_json
# Date created:		Mar 4, 2011
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	multi_json
PORTVERSION=	0.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library provide swappable JSON backends

OPTIONS=	JSON "JSON implementation as a Ruby extension in C" off \
		JSON_PURE "JSON implementation in pure Ruby" on \
		YAJL_RUBY "Yajl JSON stream-based parser library" off

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_JSON)
RUN_DEPENDS+=	rubygem-json>=0:${PORTSDIR}/devel/rubygem-json
.endif

.if defined(WITH_JSON_PURE)
RUN_DEPENDS+=	rubygem-json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure
.endif

.if defined(WITH_YAJL_RUBY)
RUN_DEPENDS+=	rubygem-yajl-ruby>=0:${PORTSDIR}/devel/rubygem-yajl-ruby
.endif

.include <bsd.port.post.mk>

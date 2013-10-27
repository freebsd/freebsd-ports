# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multi_json
PORTVERSION=	1.8.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library provide swappable JSON backends

LICENSE=	MIT

OPTIONS_DEFINE=	JSON JSON_PURE YAJL_RUBY
JSON_DESC=	JSON implementation as a Ruby extension in C
JSON_PURE_DESC=	JSON implementation in pure Ruby
YAJL_RUBY_DESC=	Yajl JSON stream-based parser library
OPTIONS_DEFAULT=	JSON_PURE

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJSON}
RUN_DEPENDS+=	rubygem-json>=0:${PORTSDIR}/devel/rubygem-json
.endif

.if ${PORT_OPTIONS:MJSON_PURE}
RUN_DEPENDS+=	rubygem-json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure
.endif

.if ${PORT_OPTIONS:MYAJL_RUBY}
RUN_DEPENDS+=	rubygem-yajl-ruby>=0:${PORTSDIR}/devel/rubygem-yajl-ruby
.endif

.include <bsd.port.mk>

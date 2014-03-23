# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multi_json
PORTVERSION=	1.9.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library provide swappable JSON backends

LICENSE=	MIT

OPTIONS_DEFINE=	JSON JSON_PURE YAJL_RUBY
JSON_DESC=	JSON implementation as a Ruby extension in C
JSON_PURE_DESC=	JSON implementation in pure Ruby
YAJL_RUBY_DESC=	Yajl JSON stream-based parser library
OPTIONS_DEFAULT=JSON_PURE

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

JSON_RUN_DEPENDS=	rubygem-json>=0:${PORTSDIR}/devel/rubygem-json
JSON_PURE_RUN_DEPENDS=	rubygem-json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure
YAJL_RUBY_RUN_DEPENDS=	rubygem-yajl-ruby>=0:${PORTSDIR}/devel/rubygem-yajl-ruby

.include <bsd.port.mk>

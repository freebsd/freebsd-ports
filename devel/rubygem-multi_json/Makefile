PORTNAME=	multi_json
PORTVERSION=	1.16.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library provide swappable JSON backends
WWW=		https://github.com/sferik/multi_json

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem

NO_ARCH=	yes

OPTIONS_DEFINE=	JSON JSON_PURE YAJL_RUBY
OPTIONS_DEFAULT=JSON_PURE
JSON_DESC=	JSON implementation as a Ruby extension in C
JSON_PURE_DESC=	JSON implementation in pure Ruby
YAJL_RUBY_DESC=	Yajl JSON stream-based parser library

JSON_RUN_DEPENDS=	rubygem-json>=0:devel/rubygem-json
JSON_PURE_RUN_DEPENDS=	rubygem-json_pure>=0:devel/rubygem-json_pure
YAJL_RUBY_RUN_DEPENDS=	rubygem-yajl-ruby>=0:devel/rubygem-yajl-ruby

.include <bsd.port.mk>

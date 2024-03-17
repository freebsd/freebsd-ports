PORTNAME=	better_html
PORTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Better HTML for Rails
WWW=		https://github.com/Shopify/better-html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview61>=6.0:devel/rubygem-actionview61 \
		rubygem-activesupport61>=6.0:devel/rubygem-activesupport61 \
		rubygem-ast>=2.0:devel/rubygem-ast \
		rubygem-erubi>=1.4:www/rubygem-erubi \
		rubygem-parser>=2.4:devel/rubygem-parser \
		rubygem-smart_properties>0:devel/rubygem-smart_properties

USES=		gem

.include <bsd.port.mk>

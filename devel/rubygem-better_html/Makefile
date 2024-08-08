PORTNAME=	better_html
PORTVERSION=	2.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Better HTML for Rails
WWW=		https://github.com/Shopify/better-html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionview71>=6.0:devel/rubygem-actionview71 \
		rubygem-activesupport71>=6.0:devel/rubygem-activesupport71 \
		rubygem-ast>=2.0<3:devel/rubygem-ast \
		rubygem-erubi>=1.4<2:www/rubygem-erubi \
		rubygem-parser>=2.4:devel/rubygem-parser \
		rubygem-smart_properties>=0:devel/rubygem-smart_properties

USES=		gem

.include <bsd.port.mk>

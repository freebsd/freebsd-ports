PORTNAME=	packwerk
PORTVERSION=	3.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set package level boundaries between a specified set of ruby constants
WWW=		https://github.com/Shopify/packwerk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activesupport71>=6.0:devel/rubygem-activesupport71 \
		rubygem-ast>=0:devel/rubygem-ast \
		rubygem-better_html>=0:devel/rubygem-better_html \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-constant_resolver>=0.2.0:devel/rubygem-constant_resolver \
		rubygem-parallel>=0:sysutils/rubygem-parallel \
		rubygem-parser>=0:devel/rubygem-parser \
		rubygem-prism>=0.25.0:textproc/rubygem-prism \
		rubygem-sorbet-runtime>=0.5.9914:devel/rubygem-sorbet-runtime \
		rubygem-zeitwerk>=2.6.1:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/packwerk

.include <bsd.port.mk>

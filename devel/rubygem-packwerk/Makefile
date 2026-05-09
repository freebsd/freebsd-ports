PORTNAME=	packwerk
PORTVERSION=	3.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set package level boundaries between a specified set of ruby constants
WWW=		https://github.com/Shopify/packwerk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activesupport71>=6.0:devel/rubygem-activesupport71 \
		rubygem-ast>=0:devel/rubygem-ast \
		rubygem-benchmark>=0:benchmarks/rubygem-benchmark \
		rubygem-better_html>=0:devel/rubygem-better_html \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-constant_resolver>=0.3:devel/rubygem-constant_resolver \
		rubygem-parallel>=0<2:sysutils/rubygem-parallel \
		rubygem-parser>=0:devel/rubygem-parser \
		rubygem-prism>=1.4.0:textproc/rubygem-prism \
		rubygem-zeitwerk>=2.6.1:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/packwerk

.include <bsd.port.mk>

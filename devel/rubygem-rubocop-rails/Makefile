PORTNAME=	rubocop-rails
PORTVERSION=	2.25.1
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RuboCop extension focused on enforcing Rails coding conventions
WWW=		https://github.com/rubocop/rubocop-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport61>=4.2.0:devel/rubygem-activesupport61 \
		rubygem-rack>=1.1:www/rubygem-rack \
		rubygem-rubocop>=1.33.0:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=1.31.1:devel/rubygem-rubocop-ast

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubocop_project

.include <bsd.port.mk>

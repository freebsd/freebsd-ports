PORTNAME=	rubocop-rspec_rails
PORTVERSION=	2.30.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Code style checking for RSpec Rails files
WWW=		https://github.com/rubocop/rubocop-rspec_rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-rubocop>=1.61<2:devel/rubygem-rubocop \
		rubygem-rubocop-rspec>=3.0.1<4:devel/rubygem-rubocop-rspec

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

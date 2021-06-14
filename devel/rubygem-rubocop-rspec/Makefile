# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	rubocop-rspec
PORTVERSION=	2.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RuboCop plugin of code style checking for RSpec files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-rubocop>=1.0<2:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=1.1.0:devel/rubygem-rubocop-ast

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

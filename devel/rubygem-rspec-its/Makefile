PORTNAME=	rspec-its
PORTVERSION=	1.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	RSpec extension gem for attribute matching

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rspec-core>=${PORTVERSION:R}:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}:devel/rubygem-rspec-expectations

NO_ARCH=	yes
USES=		gem shebangfix
bash_CMD=	${SH}
SHEBANG_FILES=	script/test_all \
		script/update_rubygems_and_install_bundler

USE_RUBY=	yes

.include <bsd.port.mk>

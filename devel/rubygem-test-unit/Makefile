PORTNAME=	test-unit
PORTVERSION=	3.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improved version of Test::Unit bundled in Ruby
WWW=		https://test-unit.github.io/ \
		https://github.com/test-unit/test-unit

LICENSE=	BSD2CLAUSE PSFL RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_PSFL=	${WRKSRC}/PSFL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-power_assert>=0:devel/rubygem-power_assert

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/test-unit

.include <bsd.port.mk>

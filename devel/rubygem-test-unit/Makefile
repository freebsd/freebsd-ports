# Created by: Eric Freeman <freebsdports@chillibear.com>

PORTNAME=	test-unit
PORTVERSION=	3.5.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improved version of Test::Unit bundled in Ruby

LICENSE=	BSD2CLAUSE PSFL RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_PSFL=	${WRKSRC}/PSFL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-power_assert>=0:devel/rubygem-power_assert

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

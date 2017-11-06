# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	test-unit
PORTVERSION=	3.2.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improved version of Test::Unit bundled in Ruby

LICENSE=	GPLv2 PSFL RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL
LICENSE_FILE_PSFL=	${WRKSRC}/PSFL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-power_assert>=0:devel/rubygem-power_assert

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

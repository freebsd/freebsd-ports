# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	test-unit
PORTVERSION=	3.1.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improved version of Test::Unit bundled in Ruby

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-power_assert>=0:${PORTSDIR}/devel/rubygem-power_assert

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

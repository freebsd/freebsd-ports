# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	ncursesw
PORTVERSION=	1.2.4.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Wrapper to the ncurses library with wide character support

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		does not install

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

REINPLACE_ARGS=

# correct a mistake in the gemspec that prevents it being properly registered
post-install:
	@${REINPLACE_CMD} -e 's|s.date = %q{2010-11-9 13:45:50 -08:00|s.date = %q{2010-11-09|' ${PREFIX}/${GEMS_BASE_DIR}/specifications/${PORTNAME}-${PORTVERSION}.gemspec

.include <bsd.port.mk>

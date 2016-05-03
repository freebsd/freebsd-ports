# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	event-loop
PORTVERSION=	0.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.brockman.se/software/ruby-event-loop/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Event loop for Ruby

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USE_RUBY=	yes

do-configure:
	@cd ${WRKSRC} && ${RUBY} setup.rb config --prefix=${PREFIX}

do-build:
	@cd ${WRKSRC} && ${RUBY} setup.rb setup

do-install:
	@cd ${WRKSRC} && ${RUBY} setup.rb install --prefix=${STAGEDIR}

.include <bsd.port.mk>

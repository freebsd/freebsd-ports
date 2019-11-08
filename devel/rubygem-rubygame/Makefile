# Created by: ws	Christoph Kick
# $FreeBSD$

PORTNAME=	rubygame
PORTVERSION=	2.6.4
PORTREVISION=	9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Game-development extension and library for the ruby language

LICENSE=	LGPL21

RUN_DEPENDS=	rubygem-rake>=0.7.0:devel/rubygem-rake \
		rubygem-ruby-sdl-ffi>=0.1.0:devel/rubygem-ruby-sdl-ffi

NO_ARCH=	yes
USE_RUBY=	yes
USE_SDL=	gfx image mixer ttf
USES=		gem sdl

.include <bsd.port.mk>

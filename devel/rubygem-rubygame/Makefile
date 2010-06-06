# New ports collection makefile for:   rubygem-rubygame
# Date created:    28 April 2010
# Whom:	ws	Christoph Kick
#
# $FreeBSD$
#

PORTNAME=	rubygame
PORTVERSION=	2.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kick.christoph@googlemail.com
COMMENT=	A game-development extension and library for the ruby language

RUN_DEPENDS=	rubygem-ruby-sdl-ffi>=0.2:${PORTSDIR}/devel/rubygem-ruby-sdl-ffi

USE_SDL=		gfx image mixer ttf
USE_RUBY=		yes
USE_RAKE=		yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

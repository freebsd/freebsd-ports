# New ports collection makefile for:   ruby-game
# Date created:    9 June 2006
# Whom:	ws
#
# $FreeBSD$
#

PORTNAME=	game
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubygame.seul.org/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A game-development extension and library for the ruby language

USE_SDL=	gfx image ttf
USE_RUBY=	yes
USE_BZIP2=	yes
USE_RUBY_SETUP=	yes

.include <bsd.port.pre.mk>

do-patch:
		${REINPLACE_CMD} 's|"sdl-config"|"${SDL_CONFIG}"|' \
		${WRKSRC}/ext/rubygame/extconf.rb

.include <bsd.port.post.mk>

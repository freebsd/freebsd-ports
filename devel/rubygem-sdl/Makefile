# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	devel graphics audio ruby
MASTER_SITES=	RG
DISTNAME=	rubysdl-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby extension library to use SDL library

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

RUN_DEPENDS=	rubygem-opengl>=0.60.1:${PORTSDIR}/graphics/rubygem-opengl

GEM_NAME=	${DISTNAME}

USE_SDL=	mixer image ttf sdl
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>

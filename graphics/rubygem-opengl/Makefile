# Created by: Steve Wills <steve@meatwad.mouf.net>
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	0.8.0
PORTEPOCH=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	RG
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenGL wrapper for Ruby

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
USE_GL=		glut
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.8
IGNORE=	Does not work with Ruby 1.8
.endif
.include <bsd.port.post.mk>

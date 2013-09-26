# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	turing
PORTVERSION=	0.0.11
PORTREVISION=	3
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy to use and customize/extend implementation of captcha

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

RUN_DEPENDS=	rubygem-gd2>=1.0:${PORTSDIR}/graphics/rubygem-gd2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>

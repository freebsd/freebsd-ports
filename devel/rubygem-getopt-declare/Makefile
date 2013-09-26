# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	getopt-declare
PORTVERSION=	1.29
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Declaratively Expressed Command-Line Arguments via Regular Expressions

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# Workaround weird files permissions
NO_STAGE=	yes
post-install:
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f -exec ${CHMOD} 644 '{}' ';'

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>

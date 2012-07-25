# New ports collection makefile for:	rubygem-ripper
# Date created:				24 June 2012
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	ripper
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Parses Ruby source and tokenizes or builds an AST

LICENSE=	BSD

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.8
IGNORE=	is already included in Ruby 1.9 and later
.endif

.include <bsd.port.post.mk>

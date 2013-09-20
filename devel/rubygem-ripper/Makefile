# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	ripper
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Parses Ruby source and tokenizes or builds an AST

LICENSE=	BSD

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

BROKEN=		fails to build

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.8
IGNORE=	is already included in Ruby 1.9 and later
.endif

.include <bsd.port.post.mk>

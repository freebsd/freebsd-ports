# New ports collection makefile for:	ruby-criteria
# Date created:		10 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	criteria
PORTVERSION=	1.0
CATEGORIES=	databases ruby
MASTER_SITES=	http://mephle.org/Criteria/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module for SQL query abstraction, and others

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.8
IGNORE=		only works with ruby 1.8 or later
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.post.mk>

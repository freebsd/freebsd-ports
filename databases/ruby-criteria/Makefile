# New ports collection makefile for:	ruby-criteria
# Date created:		10 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	criteria
PORTVERSION=	1.1a
CATEGORIES=	databases ruby
MASTER_SITES=	http://mephle.org/Criteria/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module for SQL query abstraction, and others

BROKEN=		"Fails self-test during build"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		ChangeLog README.en

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.8
IGNORE=		only works with ruby 1.8 or later
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>

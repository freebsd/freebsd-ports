# New ports collection makefile for:	Ruby/memcache
# Date created:		26 December 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	memcache
PORTVERSION=	0.0.2
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.deveiate.org/code/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	Ruby-MemCache-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A memcached client library for Ruby

BUILD_DEPENDS=	${RUBY_SITELIBDIR}/io/reactor.rb:${PORTSDIR}/devel/ruby-io-reactor
RUN_DEPENDS=	${RUBY_SITELIBDIR}/io/reactor.rb:${PORTSDIR}/devel/ruby-io-reactor

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		README

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

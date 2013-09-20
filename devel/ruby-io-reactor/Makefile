# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	io-reactor
PORTVERSION=	1.0.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://deveiate.org/code/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	io-reactor-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module that implements an asynchronous multiplexed IO Reactor

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RAKE=	yes

NO_BUILD=	yes

DOCS=		ChangeLog README
EXAMPLES=	examples/*

BUILD_DEPENDS=	rubygem-rdoc>=0:${PORTSDIR}/devel/rubygem-rdoc

NO_STAGE=	yes
do-install:
	cd ${WRKSRC}; ${RUBY} ${RAKE_BIN} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>

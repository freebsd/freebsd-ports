# New ports collection makefile for:	Ruby/Cache
# Date created:		22 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cache
PORTVERSION=	0.3
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	pupa/ruby-cache.pkg/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library for caching objects based on the LRU algorithm

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

RUBY_RD_FILES=	${WRKSRC}/MANUAL.rd ${WRKSRC}/README.rd
DOCS=		${RUBY_RD_FILES} ${RUBY_RD_HTML_FILES}

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
.endif

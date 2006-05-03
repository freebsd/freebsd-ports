# New ports collection makefile for:	Ruby/Cache
# Date created:		22 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cache
PORTVERSION=	0.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://cvsup.theplanet.com/distfiles/ruby/ \
		http://ftp.nara.wide.ad.jp/pub/GNU/savannah/files/pupa/ruby-cache.pkg/${PORTVERSION}/ \
		http://gnu.rtin.bz/ftp/savannah/files/pupa/ruby-cache.pkg/${PORTVERSION}/ \
		http://mirror.services.wisc.edu/mirrors/gnu/savannah/files/pupa/ruby-cache.pkg/${PORTVERSION}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby library for caching objects based on the LRU algorithm

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		MANUAL.rd README.rd

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}
.endif

.include <bsd.port.mk>

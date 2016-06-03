# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

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

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for caching objects based on the LRU algorithm

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

BROKEN_RUBY22=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		MANUAL.rd README.rd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${RUBY_MODDOCDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>

# New ports collection makefile for:	Ruby-BZ2
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bz2
PORTVERSION=	0.1.0
CATEGORIES=	archivers ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes
USE_RUBY_RDTOOL=	yes

INSTALL_TARGET=	site-install

DOCS=		README.en	bz2.html	bz2.rd	\
		docs/doc

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD2} bz2.rd > bz2.html
	cd ${WRKSRC}/docs; ${RUBY} b.rb bz2; rdoc bz2.rb
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

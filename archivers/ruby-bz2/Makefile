# New ports collection makefile for:	Ruby-BZ2
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bz2
PORTVERSION=	0.1.1
CATEGORIES=	archivers ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	bz2.rd

DOCS=		Changes \
		README.en \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES} \
		docs/doc

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs; ${RUBY} b.rb bz2; ${RUBY_RDOC} bz2.rb
.endif

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

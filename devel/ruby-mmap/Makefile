# New ports collection makefile for:	Ruby-Mmap
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mmap
PORTVERSION=	0.1.8
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=	rdoc:${PORTSDIR}/textproc/ruby-rdoc
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_RD_FILES=	mmap.rd

INSTALL_TARGET=	site-install

DOCS=		Changes \
		README.en \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES} \
		docs/doc

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs; ${RUBY} b.rb mmap; ${RUBY_RDOC} mmap.rb
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

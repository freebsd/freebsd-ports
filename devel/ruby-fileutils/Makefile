# New ports collection makefile for:	Ruby-fileutils
# Date created:		8 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fileutils
PORTVERSION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS_EN=	doc-en.rd	doc-en.html
DOCS_JA=	doc-ja.rd	doc-ja.html

post-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; \
	${RUBY_RD} doc-en.rd > doc-en.html
	@cd ${WRKSRC}; \
	${RUBY_RD} doc-ja.rd > doc-ja.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>

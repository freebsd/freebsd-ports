# Ports collection makefile for:	Ruby/Romkan
# Date created:			1 May 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	romkan
PORTVERSION=	0.1
CATEGORIES=	japanese converters ruby
MASTER_SITES=	http://namazu.org/~satoru/ruby-romkan/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

EXAMPLES_JA=	test.rb
DOCS_EN=	ChangeLog romkan-en.html
DOCS_JA=	romkan-ja.html

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/romkan.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/ja
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/ja/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.post.mk>

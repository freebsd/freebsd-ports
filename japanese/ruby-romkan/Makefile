# Ports collection makefile for:	Ruby/Romkan
# Date created:			1 May 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	romkan
PORTVERSION=	0.4
CATEGORIES=	japanese converters ruby
MASTER_SITES=	http://namazu.org/~satoru/ruby-romkan/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

EXAMPLES_JA=	test.rb test.sh
DOCS_EN=	ChangeLog romkan.en.html romkan.en.rd
DOCS_JA=	romkan.ja.html romkan.ja.rd

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

do-build:
.if !defined(NOPORTDOCS)
.for f in romkan.en.rd romkan.ja.rd
	@cd ${WRKSRC}; \
	${RUBY_RD2} ${f} > ${f:R}.html
.endfor
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/romkan.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>

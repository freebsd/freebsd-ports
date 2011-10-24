# New ports collection makefile for:	Ruby-smf
# Date created:		31 March 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	smf
PORTVERSION=	0.15.12
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.funaba.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby module to handle Standard MIDI Files

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
RUBY_SHEBANG_FILES=	sample/*.rb

DOCS_EN=	MANUAL.en MANUAL.en.html MANUAL.en.rd README.en
DOCS_JA=	MANUAL MANUAL.html MANUAL.rd README
EXAMPLES=	sample/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/en
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/en/
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>

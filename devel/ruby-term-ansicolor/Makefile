# New ports collection makefile for:	ruby-term-ansicolor
# Date created:		2007-01-12
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	term-ansicolor
PORTVERSION=	1.0.4
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Term::ANSIColor for Ruby

USE_RUBY=	yes
RUBY_SETUP=	install.rb

NO_BUILD=	yes

DOCS=		doc-main.txt
EXAMPLES=	examples/*

do-install:
	@cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}
.endif

.include <bsd.port.mk>

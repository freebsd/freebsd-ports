# New ports collection makefile for:	ruby-inline
# Date created:		2003-01-30
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inline
PORTVERSION=	3.5.0
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RubyInline-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

USE_RUBY=	yes
USE_GMAKE=	yes
RUBY_SHEBANG_FILES=${WRKSRC}/inline_package

NO_BUILD=	yes

DOCS=		README.txt History.txt
EXAMPLES=	example.rb tutorial/example1.rb tutorial/example2.rb demo/*

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,install[ \t]+-m[ \t]+0555,\$${BSD_INSTALL_SCRIPT},' \
		-e 's,install[ \t]+-m[ \t]+0444,\$${BSD_INSTALL_DATA},' \
		${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${RUBY_SITELIBDIR}

post-install:
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}

.include <bsd.port.mk>

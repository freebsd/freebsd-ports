# New ports collection makefile for:	RICA
# Date created:		10 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rica
PORTVERSION=	0.10
CATEGORIES=	irc ruby
MASTER_SITES=	http://www.koka-in.org/%7Ezophos/lib/rica/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Another IRC client framework for Ruby

USE_BZIP2=	yes
USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MODULES=	rica.rb \
		ctcpresponder.rb \
		connectiondiag.rb \
		logholder.rb

DOCS=		CHANGES	README	classes_and_methods.txt	event.lst *.png
EXAMPLES=	erica.* ricaco.rb rica-example.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}/
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

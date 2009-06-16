# New ports collection makefile for:	Ruby-Poll
# Date created:		25 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	poll
PORTVERSION=	0.03
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.deveiate.org/code/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	Ruby-Poll-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An object-oriented interface to the poll(2) system call for Ruby

USE_BZIP2=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/examples/*.rb
INSTALL_TARGET=	site-install

DOCS=		ChangeLog README docs/html
EXAMPLES=	examples/*.rb

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY} makedocs.rb
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>

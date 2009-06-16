# New ports collection makefile for:	rbison
# Date created:		2 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbison
PORTVERSION=	0.0.7
PORTREVISION=	3
CATEGORIES=	devel ruby
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generates a Ruby parser class from a Bison-like specification file

USE_BISON=	run
USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/rbison

DOCS=		ChangeLog		README
EXAMPLES=	CalcFileLexer.rb	CalcStringLexer.rb	\
		calc.in 		calc.ry			calc_test.rb

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbison ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

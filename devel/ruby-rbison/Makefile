# New ports collection makefile for:	rbison
# Date created:		2 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbison
PORTVERSION=	0.0.7
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.cs.umass.edu/~aseltine/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	bison:${PORTSDIR}/devel/bison

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/rbison

DOCS=		ChangeLog		README
EXAMPLES=	CalcFileLexer.rb	CalcStringLexer.rb	\
		calc.in 		calc.ry			calc_test.rb

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbison ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/rbison
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/rbison/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/rbison
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rbison/
.endfor
.endif

.include <bsd.port.mk>

# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rbison
PORTVERSION=	0.0.7
PORTREVISION=	4
CATEGORIES=	devel ruby
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generates a Ruby parser class from a Bison-like specification file

USES=		bison shebangfix
USE_RUBY=	yes

SHEBANG_FILES=	rbison

DOCS=		ChangeLog README
EXAMPLES=	CalcFileLexer.rb CalcStringLexer.rb	\
		calc.in calc.ry calc_test.rb

NO_BUILD=	yes

BROKEN_RUBY22=	Builds but does not run
BROKEN_RUBY23=	Builds but does not run

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Does not work on modern ruby
EXPIRATION_DATE=	2017-01-28

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbison ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	Ruby/setup.rb
# Date created:		11 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	setup.rb
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME:R}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:R}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

_SCRIPTS=	install.rb setup.rb

RUBY_SHEBANG_FILES=	${_SCRIPTS:S:^:${WRKSRC}/ruby-:}

DOCS_EN=	doc.en/* usage-en.txt
DOCS_JA=	doc.ja/* usage-ja.txt

post-extract:
.for f in ${_SCRIPTS}
	${CP} -p ${WRKSRC}/${f} ${WRKSRC}/ruby-${f}
.endfor

do-install:
.for f in ${_SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/ruby-${f} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>

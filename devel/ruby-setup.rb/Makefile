# New ports collection makefile for:	Ruby/setup.rb
# Date created:		11 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	setup.rb
PORTVERSION=	3.1.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/ \
		http://www.ruby-lang.org/~knu/backup/
MASTER_SITE_SUBDIR=	${PORTNAME:R}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:R}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	doc.en/* usage-en.txt
DOCS_JA=	doc.ja/* usage-ja.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/install.rb ${WRKSRC}/setup.rb ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>

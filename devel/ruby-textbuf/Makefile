# New ports collection makefile for:	Ruby-
# Date created:		19 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	textbuf
PORTVERSION=	0.3.8
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.xdsl.ne.jp/Cd/aamine/soft/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

DOCS_EN=	README.en
DOCS_JA=	README.ja

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/textbuf/ja
	${INSTALL_DATA} ${WRKSRC}/stest.rb ${RUBY_EXAMPLESDIR}/textbuf/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_EXAMPLESDIR}/textbuf/ja/
	${MKDIR} ${RUBY_DOCDIR}/textbuf/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/textbuf/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/textbuf/ja/
.endfor
.endif

.include <bsd.port.mk>

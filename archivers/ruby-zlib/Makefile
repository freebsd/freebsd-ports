# New ports collection makefile for:	Ruby-zlib
# Date created:		12 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	zlib
PORTVERSION=	0.5.0.p3
CATEGORIES=	archivers ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION:S/.p/-pre/}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog zlib.rd.en zlib.en.html
DOCS_JA=	zlib.rd.ja zlib.ja.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/zlib/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib/ja/
.endfor
.endif

.include <bsd.port.mk>

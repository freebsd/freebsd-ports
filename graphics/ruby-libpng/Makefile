# New ports collection makefile for:	Ruby/libpng
# Date created:		27 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libpng
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	${MASTER_SITE_LOCAL}
#		http://www.isc.meiji.ac.jp/~ee77038/ruby/program/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

INSTALL_TARGET=	site-install

DOCS_JA=	readme.ja.html	readme.ja.rd	readme.ja.txt
EXAMPLES_EN=	es.png		png.rb		pngtest.rb	pngtest.sh	\
		sample/0.png	sample/1.png	sample/2.png	sample/3.png	\
		sample/4.png	sample/5.png	sample/6.png	sample/7.png	\
		sample/8.png	sample/9.png	sample/pngcat.rb

.if !defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}; \
	${RUBY_RD} readme.ja.rd > readme.ja.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/libpng
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/libpng/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/libpng/ja
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/libpng/ja/
.endfor
.endif

.include <bsd.port.mk>

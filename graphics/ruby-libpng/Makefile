# New ports collection makefile for:	Ruby/libpng
# Date created:		27 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libpng
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.isc.meiji.ac.jp/~ee77038/ruby/program/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	knu
PATCHFILES=	ruby-libpng-0.3.3.patch.gz

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

DOCS_JA=	readme.ja.html	readme.ja.rd	readme.ja.txt
EXAMPLES_EN=	es.png		png.rb		pngtest.rb	pngtest.sh	\
		test.rb	\
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

# New ports collection makefile for:	Ruby/libpng
# Date created:		27 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#
#		http://www.isc.meiji.ac.jp/~ee77038/ruby/program/

PORTNAME=	libpng
PORTVERSION=	0.3.3
PORTREVISION=	4
CATEGORIES=	graphics ruby
MASTER_SITES=	LOCAL/knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A libpng wrapper class for Ruby

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	readme.ja.rd

DOCS_JA=	readme.ja.txt \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}
EXAMPLES_EN=	es.png		png.rb		pngtest.rb	pngtest.sh	\
		sample/0.png	sample/1.png	sample/2.png	sample/3.png	\
		sample/4.png	sample/5.png	sample/6.png	sample/7.png	\
		sample/8.png	sample/9.png	sample/pngcat.rb

post-configure:
	@${REINPLACE_CMD} -E -e "s| -L'?\.'?||" ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>

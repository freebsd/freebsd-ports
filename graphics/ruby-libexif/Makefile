# New ports collection makefile for:	ruby-libexif
# Date created:		6 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libexif
PORTVERSION=	0.1.1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://tam.0xfa.com/ruby-libexif/pkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	exif.8:${PORTSDIR}/graphics/libexif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDTOOL=	yes

INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog	README	exif.rd.en	exif.en.html
DOCS_JA=				exif.rd.ja	exif.ja.html

.if !defined(NOPORTDOCS)
post-build:
.for lang in en ja
	cd ${WRKSRC}; ${RUBY_RD2} exif.rd.${lang} > exif.${lang}.html
.endfor
.endif

post-install:
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

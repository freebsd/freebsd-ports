# New ports collection makefile for:	ruby-libexif
# Date created:		6 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libexif
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://tam.0xfa.com/ruby-libexif/pkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension library for libexif

LIB_DEPENDS=	exif.10:${PORTSDIR}/graphics/libexif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	exif.rd.en	exif.rd.ja

DOCS_EN=	ChangeLog	README \
		${RUBY_RD_FILES:M*.rd.en} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.rd.ja} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

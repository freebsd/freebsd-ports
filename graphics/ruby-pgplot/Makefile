# New ports collection makefile for:	Ruby/PGPLOT
# Date created:		26 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pgplot
PORTVERSION=	0.1.2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.ir.isas.ac.jp/~masa/ruby/dist/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb_${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to PGPLOT graphics library

LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

DOCS_EN=	FuncUsage	README.en
DOCS_JA=	README.jp
EXAMPLES_EN=	pgdemo*.rb	test/*.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>

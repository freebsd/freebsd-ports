# New ports collection makefile for:	Ruby/SVG
# Date created:		8 July 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	svg
PORTVERSION=	1.0.3
CATEGORIES=	graphics ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ruby-svg/2288
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby library for generating SVG files

USE_RUBY=	yes
USE_RUBY_FEATURES=	zlib

NO_BUILD=	yes

DOCS_EN=	README.en.rd
DOCS_JA=	README.ja.rd

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/svg
	${INSTALL_DATA} ${WRKSRC}/lib/svg/*.rb ${RUBY_SITELIBDIR}/svg/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	Ruby-zoom
# Date created:		16 September 2005
# Whom:			Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	zoom
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A Ruby binding to the Z39.50 Object-Orientation Model (ZOOM)

LIB_DEPENDS=	yaz.3:${PORTSDIR}/net/yaz

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCS=		ChangeLog README doc/ascii/api.txt doc/xhtml/*

RUBY_REQUIRE=	Ruby > 180

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>

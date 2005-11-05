# New ports collection makefile for:	rcairo
# Date created:				16 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/ruby-cairo/Makefile,v 1.2 2005/10/17 07:05:40 mezz Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.0.0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Ruby binding for Cairo

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		AUTHORS COPYING ChangeLog GPL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

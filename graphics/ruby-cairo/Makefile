# New ports collection makefile for:	rcairo
# Date created:				16 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/graphics/ruby-cairo/Makefile,v 1.1 2008/06/17 16:11:09 mezz Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.6.2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Ruby binding for Cairo

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_GNOME=	pkgconfig
USE_RUBY=	yes
USE_RUBY_EXTCONF=yes
CONFIGURE_ARGS+=--ruby=${RUBY}

DOCS=		AUTHORS COPYING ChangeLog GPL NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/lib/pkgconfig|${LOCALBASE}/libdata/pkgconfig|g' \
		${WRKSRC}/pkg-config.rb

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/agg
	@${INSTALL_DATA} ${WRKSRC}/samples/*.rb ${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/samples/agg/*.rb ${RUBY_MODEXAMPLESDIR}/agg/
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

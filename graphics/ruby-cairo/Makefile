# New ports collection makefile for:	rcairo
# Date created:				16 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/ruby-cairo/Makefile,v 1.9 2008/10/19 23:20:49 mezz Exp $
#

PORTNAME=	cairo
PORTVERSION=	1.8.0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/agg
	@${INSTALL_DATA} ${WRKSRC}/samples/*.rb ${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/samples/agg/*.rb ${RUBY_MODEXAMPLESDIR}/agg/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

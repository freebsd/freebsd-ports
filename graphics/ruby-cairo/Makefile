# $FreeBSD$
#   $MCom: ports/graphics/ruby-cairo/Makefile,v 1.9 2008/10/19 23:20:49 mezz Exp $

PORTNAME=	cairo
PORTVERSION=	1.12.2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	r${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Cairo

BUILD_DEPENDS=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_GNOME=	pkgconfig
USE_RUBY=	yes
USE_RUBY_EXTCONF=yes
CONFIGURE_ARGS+=--ruby=${RUBY}

DOCS=		AUTHORS COPYING GPL NEWS

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

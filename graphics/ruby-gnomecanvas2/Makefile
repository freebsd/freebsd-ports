# New ports collection makefile for:	Ruby/GnomeCanvas2
# Date created:		24 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnomecanvas2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	graphics ruby gnome
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	mezz7@cox.net
COMMENT=	Ruby binding for GnomeCanvas2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/libart2.so:${PORTSDIR}/graphics/ruby-libart2

USE_RUBY=	yes
USE_GNOME=	libgnomecanvas
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gnomecanvas
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog \
		README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

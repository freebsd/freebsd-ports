# New ports collection makefile for:	Ruby/GConf2
# Date created:		20 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gconf2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to GConf2

LIB_DEPENDS=	gconf-2.5:${PORTSDIR}/devel/gconf2
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gconf
INSTALL_TARGET=	site-install

DOCS=	ChangeLog \
	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

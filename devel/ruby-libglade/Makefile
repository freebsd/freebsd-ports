# New ports collection makefile for:	Ruby-libglade
# Date created:		8 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel ruby gnome
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A wrapper library of libglade for Ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		${RUBY_SITEARCHLIBDIR}/gnome.so:${PORTSDIR}/x11/ruby-gnome
LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GNOME=	yes

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	Ruby/Libglade2
# Date created:		8 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libglade2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	devel ruby gnome
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby binding for Libglade2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
LIB_DEPENDS=	glade-2.0.0:${PORTSDIR}/devel/libglade2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/libglade
INSTALL_TARGET=	site-install

RUBY_SHEBANG_FILES=	${WRKSRC}/bin/ruby-glade-create-template

DOCS=		ChangeLog \
		README

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-glade-create-template ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

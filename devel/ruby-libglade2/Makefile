# New ports collection makefile for:	Ruby/Libglade2
# Date created:		8 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#   $MCom: ports/devel/ruby-libglade2/Makefile,v 1.2 2005/10/17 07:05:40 mezz Exp $
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

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Libglade2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

USE_RUBY=	yes
USE_GNOME=	libglade2
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/libglade
INSTALL_TARGET=	site-install

RUBY_SHEBANG_FILES=	${WRKSRC}/bin/ruby-glade-create-template

DOCS=		COPYING.LIB ChangeLog README

post-patch: general-patch

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/po/ja
	@${INSTALL_DATA} ${WRKSRC}/sample/README ${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/sample/*.glade ${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/sample/po/*.pot ${RUBY_MODEXAMPLESDIR}/po/
	@${INSTALL_DATA} ${WRKSRC}/sample/po/ja/*.po ${RUBY_MODEXAMPLESDIR}/po/ja/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

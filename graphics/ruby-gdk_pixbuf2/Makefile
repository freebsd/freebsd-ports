# New ports collection makefile for:	ruby-gdk_pixbuf
# Date created:		28 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdk_pixbuf
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	graphics ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
USE_GLIB=	yes

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-glib-config="${GLIB_CONFIG}"

DOCS_EN=	ChangeLog	README

post-extract:
	${MV} ${WRKSRC:S/gdk_pixbuf$/gdkpixbuf/} ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>

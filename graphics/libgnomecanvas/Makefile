# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/libgnomecanvas/Makefile,v 1.79 2010/09/28 07:31:27 kwm Exp $

PORTNAME=	libgnomecanvas
PORTVERSION=	2.30.3
PORTREVISION?=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphics library for GNOME

USES+=		tar:bzip2

.if !defined(REFERENCE_PORT)

USES+=		gettext gmake libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	intltool libglade2 libartlgpl2 referencehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--enable-glade \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

.endif

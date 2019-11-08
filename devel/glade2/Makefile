# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/glade2/Makefile,v 1.20 2007/08/04 03:51:29 marcus Exp $

PORTNAME=	glade
PORTVERSION=	2.12.2
PORTREVISION=	8
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librarian.so:textproc/rarian

INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake gnome localbase:ldflags \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gtk20

CONFIGURE_ARGS+=	--disable-gnome-db --disable-nome

.include <bsd.port.mk>

# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/glade2/Makefile,v 1.20 2007/08/04 03:51:29 marcus Exp $

PORTNAME=	glade
PORTVERSION=	2.12.2
PORTREVISION=	7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

LIB_DEPENDS=	rarian.0:${PORTSDIR}/textproc/rarian

USE_BZIP2=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack gtk20 desktopfileutils
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GNOME
OPTIONS_DEFAULT=GNOME
GNOME_DESC=	Gnome support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=		libgailgnome libgnomeui
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

CONFIGURE_ARGS+=	--disable-gnome-db

.include <bsd.port.mk>

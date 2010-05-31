# New ports collection makefile for:	glade2
# Date created:		02 June 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade2/Makefile,v 1.20 2007/08/04 03:51:29 marcus Exp $
#

PORTNAME=	glade
PORTVERSION=	2.12.2
PORTREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

LIB_DEPENDS=	rarian.0:${PORTSDIR}/textproc/rarian

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk20 desktopfileutils
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	GNOME "Enable gnome support" on #\
#		GNOMEDB "Enable libgnomedb support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS+=	--disable-gnome
.else
USE_GNOME+=		libgailgnome libgnomeui
CONFIGURE_ARGS+=	--enable-gnome
.endif

#.if defined(WITH_GNOMEDB)
#USE_GNOME+=		libgnomedb
#CONFIGURE_ARGS+=	--enable-gnome-db
#.else
CONFIGURE_ARGS+=	--disable-gnome-db
#.endif

.include <bsd.port.post.mk>

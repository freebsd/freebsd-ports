# New ports collection makefile for:	Planner
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/planner/Makefile,v 1.4 2007/05/19 21:36:03 marcus Exp $
#

PORTNAME=	planner
PORTVERSION=	0.14.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for GNOME 2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libgnomeprintui \
		libgsf desktopfileutils
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-python \
		--disable-dotnet
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	planner.schemas

MAN1=		planner.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgda2}!=""
USE_GNOME+=	libgda2
CONFIGURE_ARGS+=--enable-database=yes
PLIST_SUB+=	GDA=""
.else
PLIST_SUB+=	GDA="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>

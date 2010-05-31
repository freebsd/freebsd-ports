# New ports collection makefile for:	Planner
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/deskutils/planner/Makefile,v 1.4 2009/04/16 00:34:24 kwm Exp $
#

PORTNAME=	planner
PORTVERSION=	0.14.4
PORTREVISION=	4
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
		--disable-python-plugin
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	planner.schemas

MAN1=		planner.1

OPTIONS=	GDA "Enable database support (though libgda)" off \
		EVO "Enable evolution data server support" off

.include <bsd.port.pre.mk>


.if defined(WITH_GDA)
USE_GNOME+=	libgda3
CONFIGURE_ARGS+=--with-database=gda3
PLIST_SUB+=	GDA=""
.else
PLIST_SUB+=	GDA="@comment "
.endif

.if defined(WITH_EVO)
USE_GNOME+=	evolutiondataserver
CONFIGURE_ARGS+=--enable-eds --enable-eds-backend
PLIST_SUB+=	EVO=""
.else
PLIST_SUB+=	EVO="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>

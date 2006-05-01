# New ports collection makefile for:	glade2
# Date created:		02 June 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade2/Makefile,v 1.16 2005/10/09 20:01:49 marcus Exp $
#

PORTNAME=	glade
PORTVERSION=	2.12.1
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
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

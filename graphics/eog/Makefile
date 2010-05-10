# New ports collection makefile for:	eog2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/eog/Makefile,v 1.113 2010/04/27 18:11:36 kwm Exp $
#

PORTNAME=	eog
PORTVERSION=	2.30.1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye Of Gnome image viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack librsvg2 desktopfileutils \
		gnomedesktop
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	eog.schemas

.include <bsd.port.pre.mk>

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if !defined(WITHOUT_EXIF) || (exists(${LOCALBASE}/lib/libexif.so.12) || \
	defined(WITH_EXIF))
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
PLIST_SUB+=	EXIF="@comment "
.endif

.if !defined(WITHOUT_EXEMPI) || (exists(${LOCALBASE}/lib/libexempi.so)) || \
    	defined(WITH_EXEMPI)
LIB_DEPENDS+=	exempi.3:${PORTSDIR}/textproc/exempi
_WITH_EXEMPI=	yes
.endif

.if ${_WITH_EXIF}=="yes" || ${_WITH_EXEMPI}=="yes"
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

.if ${HAVE_GNOME:Mpygnome2}!=""
USE_GNOME+=	pygnome2
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
.endif

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.post.mk>

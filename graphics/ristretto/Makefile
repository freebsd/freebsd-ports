# New ports collection makefile for:	ristretto
# Date created:		2007-08-27
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ristretto
PORTVERSION=	0.3.4
CATEGORIES=	graphics xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	An image viewer with Xfce integration

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack desktopfileutils pkgconfig
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_XFCE=	configenv libmenu libutil xfconf libexo
USE_XORG=	sm x11

.if defined(NOPORTDOCS)
PLIST_SUB+=	DOCS="@comment "
post-patch:
	@${REINPLACE_CMD} -e 's| docs||' ${WRKSRC}/Makefile.in
.else
PLIST_SUB+=	DOCS=""
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>

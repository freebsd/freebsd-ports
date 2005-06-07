# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $Id: Makefile,v 1.7 2005/05/13 00:56:00 tmclau02 Exp $
# $FreeBSD$
#

PORTNAME=	tomboy
PORTVERSION=	0.3.2
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.beatniksoftware.com/tomboy/releases/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp

USE_GNOME=	gnomehack gnometarget intltool gnomeprefix gnomepanel
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		tomboy.1
GCONF_SCHEMAS=	tomboy.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>

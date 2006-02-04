# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.17 2005/10/23 20:57:55 tmclau02 Exp $
#

PORTNAME=	tomboy
PORTVERSION=	0.3.3
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.beatniksoftware.com/tomboy/releases/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp

USE_GNOME=	gnomehack gnometarget intltool gnomeprefix gnomepanel
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		tomboy.1
GCONF_SCHEMAS=	tomboy.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>

# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/bijiben/Makefile 20065 2014-11-11 07:36:48Z gusi $

PORTNAME=	bijiben
PORTVERSION=	3.14.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		evolution>=3.0.0:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3
RUN_DEPENDS=	evolution>=3.0.0:${PORTSDIR}/mail/evolution
USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig shared-mime-info tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# needed for webkit
USES+=		compiler:c++11-lib

.include <bsd.port.mk>

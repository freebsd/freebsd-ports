# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/colord-gtk/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	colord-gtk
PORTVERSION=	0.1.25
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

BUILD_DEPENDS=	colord>=0.1.20:${PORTSDIR}/graphics/colord
LIB_DEPENDS=	colord:${PORTSDIR}/graphics/colord \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		dbus-1:${PORTSDIR}/devel/dbus \
		lcms2:${PORTSDIR}/graphics/lcms2

USE_XZ=		yes
USE_GNOME=	gnomehier gtk30 intlhack introspection:build
USES=		gettext gmake pathfix pkgconfig
USE_SQLITE=	3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc-html=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

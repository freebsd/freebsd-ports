# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/colord-gtk/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	colord-gtk
PORTVERSION=	0.1.25
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/colord/releases/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices

BUILD_DEPENDS=	colord>=0.1.20:${PORTSDIR}/graphics/colord
LIB_DEPENDS=	libcolord.so:${PORTSDIR}/graphics/colord \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		liblcms2.so:${PORTSDIR}/graphics/lcms2

USE_GNOME=	gnomehier gtk30 intlhack introspection:build
USES=		gettext gmake pathfix pkgconfig tar:xz libtool
USE_SQLITE=	3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc-html=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g' \
		-e 's|-Wempty-body||g' \
		-e 's|-Wignored-qualifiers||g' \
		-e 's|-Wtype-limits||g' \
		-e 's|-Wmissing-parameter-type||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

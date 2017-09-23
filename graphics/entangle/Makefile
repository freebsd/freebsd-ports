# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	entangle
PORTVERSION=	0.7.2
CATEGORIES=	graphics
MASTER_SITES=	http://entangle-photo.org/download/sources/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Digital camera tethered control and capture program

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/share/icons/mate/scalable/devices/camera-photo-symbolic.svg:x11-themes/mate-icon-theme \
		itstool:textproc/itstool
LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2 \
		libdbus-glib-1.so:devel/dbus-glib \
		liblcms2.so:graphics/lcms2 \
		libgexiv2.so:graphics/gexiv2 \
		libraw_r.so:graphics/libraw \
		libpeas-1.0.so:devel/libpeas
RUN_DEPENDS:=	${BUILD_DEPENDS:Nitstool*} \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py3-libpeas

USES=		gettext-tools gmake libtool pkgconfig python:3
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gtk30 intltool introspection
USE_GSTREAMER1=	core
USE_XORG=	xext
GLIB_SCHEMAS=	org.entangle-photo.manager.gschema.xml
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e '/checking for GUDEV/,+93d ; \
		s,gnome-icon-theme-symbolic,mate-icon-theme, ; \
		s,/usr/share/icons/gnome,${LOCALBASE}/share/icons/mate,' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,_udev,,' \
		${WRKSRC}/src/backend/entangle-camera-list.c

.include <bsd.port.mk>

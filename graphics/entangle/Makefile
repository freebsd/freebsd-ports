# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	entangle
DISTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://entangle-photo.org/download/sources/

MAINTAINER=	woodsb02@gmail.com
COMMENT=	Digital camera tethered control and capture program

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/share/icons/mate/scalable/devices/camera-photo-symbolic.svg:${PORTSDIR}/x11-themes/mate-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2 \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libgexiv2.so:${PORTSDIR}/graphics/gexiv2 \
		libraw_r.so:${PORTSDIR}/graphics/libraw \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas
RUN_DEPENDS:=	${BUILD_DEPENDS:Nitstool*} \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:${PORTSDIR}/devel/py3-libpeas

USES=		gettext-tools gmake libtool pkgconfig python:3
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 introspection:build
GLIB_SCHEMAS=	org.entangle-photo.manager.gschema.xml
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

# XXX: it would be nice if one day this option would be passed automatically
# to configure scripts that support it :)
.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	--disable-silent-rules
.endif

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

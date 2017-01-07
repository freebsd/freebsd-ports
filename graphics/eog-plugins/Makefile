# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eog-plugins
PORTVERSION=	3.16.3
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

BUILD_DEPENDS=	eog:graphics/eog
LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libexif.so:graphics/libexif \
		libpeas-1.0.so:devel/libpeas
RUN_DEPENDS=	eog:graphics/eog

PORTSCOUT=	limitw:1,even

USE_GNOME=	intltool gtk30
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.eog.plugins.exif-display.gschema.xml

OPTIONS_DEFINE=	CHAMPLAIN PYTHON
OPTIONS_DEFAULT=CHAMPLAIN PYTHON
OPTIONS_SUB=	yes
CHAMPLAIN_DESC=	Champlain map plugin

CHAMPLAIN_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain
CHAMPLAIN_USE=		GL=gl
PYTHON_CONFIGURE_ENABLE=python
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py3-libpeas
PYTHON_USES=		python:3
PYTHON_VARS=		GLIB_SCHEMAS+="org.gnome.eog.plugins.export-to-folder.gschema.xml org.gnome.eog.plugins.fullscreenbg.gschema.xml org.gnome.eog.plugins.pythonconsole.gschema.xml"

post-patch-CHAMPLAIN-off:
	@${REINPLACE_CMD} -e 's|champlain-gtk|disabled-champlain-gtk|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^DEFAULT_PLUGINS=/,/^$$/ s/map//' \
		${WRKSRC}/configure

.include <bsd.port.mk>

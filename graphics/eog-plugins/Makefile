# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/eog-plugins3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	eog-plugins
PORTVERSION=	3.6.1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

BUILD_DEPENDS=	eog>=3.6.0:${PORTSDIR}/graphics/eog
LIB_DEPENDS=	libgdata.so.13:${PORTSDIR}/devel/libgdata \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas
RUN_DEPENDS=	eog>=3.6.0:${PORTSDIR}/graphics/eog

USE_XZ=		yes
USE_GNOME=	gnomeprefix intlhack gtk30
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.eog.plugins.exif-display.gschema.xml

OPTIONS_DEFINE=	CHAMPLAIN PYTHON
OPTIONS_DEFAULT=CHAMPLAIN PYTHON
CHAMPLAIN_DESC=	Champlain map plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHAMPLAIN}
USE_GL=		gl
LIB_DEPENDS+=	libchamplain-0.12.so:${PORTSDIR}/graphics/libchamplain
PLIST_SUB+=	CHAMPLAIN=""
.else
PLIST_SUB+=	CHAMPLAIN="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--enable-python
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
GLIB_SCHEMAS+=	org.gnome.eog.plugins.export-to-folder.gschema.xml \
		org.gnome.eog.plugins.fullscreenbg.gschema.xml \
		org.gnome.eog.plugins.pythonconsole.gschema.xml
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ! ${PORT_OPTIONS:MCHAMPLAIN}
post-patch:
	@${REINPLACE_CMD} -e 's|champlain-gtk|disabled-champlain-gtk|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^DEFAULT_PLUGINS=/,/^$$/ s/map//' \
		${WRKSRC}/configure
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/eog/plugins/lib*.so

.include <bsd.port.mk>

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
CHAMPLAIN_DESC=	Champlain map plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHAMPLAIN}
USE_GL=		gl
LIB_DEPENDS+=	libchamplain-0.12.so:graphics/libchamplain
PLIST_SUB+=	CHAMPLAIN=""
.else
PLIST_SUB+=	CHAMPLAIN="@comment "
.endif

PLIST_SUB+=	PYVER=${PYTHON_VER:S|.||}
.if ${PORT_OPTIONS:MPYTHON}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py3-libpeas
CONFIGURE_ARGS+=--enable-python
USES+=		python:3
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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION}

.include <bsd.port.post.mk>

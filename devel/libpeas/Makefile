# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpeas
PORTVERSION=	1.12.1
PORTREVISION?=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

LIBPEAS_SLAVE?=	no

.if ${LIBPEAS_SLAVE} == no
PORTSCOUT=	limitw:1,even
.else
LIB_DEPENDS+=	libpeas-1.0.so:${PORTSDIR}/devel/libpeas
PORTSCOUT=	ignore:1
.endif

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack introspection:build
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--disable-glade-catalog
PLIST=          ${.CURDIR}/pkg-plist

.if ${LIBPEAS_SLAVE} == no
OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SEED
OPTIONS_DEFAULT=SEED
SEED_DESC=	JavaScript support based on webkit-gtk3
SEED_LIB_DEPENDS=	libseed-gtk3.so:${PORTSDIR}/devel/seed
SEED_CONFIGURE_ENABLE=	seed
.else
CONFIGURE_ARGS+=	--disable-seed
.endif

.if ${LIBPEAS_SLAVE} == python2
USES+=		python:2
USE_GNOME+=	pygobject3
.else
CONFIGURE_ARGS+=	--disable-python2
.endif

.if ${LIBPEAS_SLAVE} == python3
USES+=		python:3
USE_GNOME+=	py3gobject3
.else
CONFIGURE_ARGS+=	--disable-python3
.endif

# lua needs lua 5.1 and devel/lua-lgi. The latter is build for lua 5.2 however..
CONFIGURE_ARGS+=	--disable-lua5.1 --disable-luajit

.include <bsd.port.mk>

# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libpeas/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	libpeas
PORTVERSION=	1.10.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 introspection:build
USE_PYTHON=	3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--disable-glade-catalog

OPTIONS_DEFINE=	PYTHON SEED
OPTIONS_DEFAULT=PYTHON SEED
SEED_DESC=	JavaScript support based on webkit-gtk3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSEED}
CONFIGURE_ARGS+=--enable-seed=yes
LIB_DEPENDS=	libseed-gtk3.so:${PORTSDIR}/devel/seed
PLIST_SUB+=	SEED=""
.else
CONFIGURE_ARGS+=--enable-seed=no
PLIST_SUB+=	SEED="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--disable-python2 --enable-python3
USE_GNOME+=	py3gobject3
PLIST_SUB+=	PYTHONS=""
.else
CONFIGURE_ARGS+=--disable-python2 --disable-python3
PLIST_SUB+=	PYTHONS="@comment "
.endif

.include <bsd.port.mk>

# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpeas
PORTVERSION=	1.20.0
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Next evolution of the Gedit plugins engine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

LIBPEAS_SLAVE?=	no

.if ${LIBPEAS_SLAVE} == no
PORTSCOUT=	limitw:1,even
.else
LIB_DEPENDS+=	libpeas-1.0.so:devel/libpeas
PORTSCOUT=	ignore:1
.endif

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--disable-glade-catalog
PLIST=          ${.CURDIR}/pkg-plist

.if ${LIBPEAS_SLAVE} == python
USES+=		python
USE_PYTHON=	flavors
.if ${FLAVOR:Upy27:Mpy2*}
USE_GNOME+=	pygobject3
CONFIGURE_ARGS+=	--disable-python3
BUILD_WRKSRC=	${WRKSRC}/loaders/python
INSTALL_WRKSRC=	${WRKSRC}/loaders/python
.else
USE_GNOME+=	py3gobject3
CONFIGURE_ARGS+=	--disable-python2 \
			ac_cv_path_PYTHON3_CONFIG=${LOCALBASE}/bin/python${PYTHON_VER}-config
BUILD_WRKSRC=	${WRKSRC}/loaders/python3
INSTALL_WRKSRC=	${WRKSRC}/loaders/python3
.endif
.else
CONFIGURE_ARGS+=	--disable-python2 --disable-python3
.endif

# lua needs lua 5.1 and devel/lua-lgi. The latter is build for lua 5.2 however..
CONFIGURE_ARGS+=	--disable-lua5.1 --disable-luajit

.include <bsd.port.mk>

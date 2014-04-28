# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/accessibility/orca/Makefile 19537 2014-04-15 21:34:06Z gusi $

PORTNAME=	orca
PORTVERSION=	3.12.1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py3-dbus \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py3-xdg \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py3-cairo \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libatspi.so:${PORTSDIR}/accessibility/at-spi2-core
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:${PORTSDIR}/devel/py3-dbus \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py3-xdg \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py3-cairo

# conflict with py*-json-py because orca uses the json from python itself
# and py*-json-py shadows this.
CONFLICTS=	py*-json-py-[0-9]*

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 py3gobject3
USE_PYTHON=	3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.mk>

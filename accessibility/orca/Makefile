# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	orca
PORTVERSION=	3.18.2
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	py3?-dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		py3?-xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		py3?-cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		itstool:textproc/itstool
LIB_DEPENDS=	libatspi.so:accessibility/at-spi2-core
RUN_DEPENDS=	py3?-dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		py3?-speech-dispatcher>=0:accessibility/py-speech-dispatcher@${PY_FLAVOR} \
		py3?-atspi>=0:accessibility/py-atspi@${PY_FLAVOR} \
		py3?-xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		py3?-cairo>=0:graphics/py-cairo@${PY_FLAVOR}

# conflict with py*-json-py because orca uses the json from python itself
# and py*-json-py shadows this.
CONFLICTS=	py*-json-py-[0-9]*
PORTSCOUT=	limitw:1,even

NO_ARCH=	yes
USES=		gettext gmake gnome pathfix pkgconfig python:3.4+ tar:xz
USE_GNOME=	gtk30 py3gobject3 intlhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.mk>

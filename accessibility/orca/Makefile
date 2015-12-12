# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	orca
PORTVERSION=	3.16.3
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader

BUILD_DEPENDS=	py3?-dbus>=0:${PORTSDIR}/devel/py3-dbus \
		py3?-xdg>=0:${PORTSDIR}/devel/py3-xdg \
		py3?-cairo>=0:${PORTSDIR}/graphics/py3-cairo \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libatspi.so:${PORTSDIR}/accessibility/at-spi2-core
RUN_DEPENDS=	py3?-dbus>=0:${PORTSDIR}/devel/py3-dbus \
		py3?-atspi>=0:${PORTSDIR}/accessibility/py3-atspi \
		py3?-xdg>=0:${PORTSDIR}/devel/py3-xdg \
		py3?-cairo>=0:${PORTSDIR}/graphics/py3-cairo

# conflict with py*-json-py because orca uses the json from python itself
# and py*-json-py shadows this.
CONFLICTS=	py*-json-py-[0-9]*
PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig python:3 tar:xz
USE_GNOME=	gtk30 py3gobject3 intlhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/src/orca/orca_i18n.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION} \
		PYVER=${PYTHON_VER:S/.//}

.include <bsd.port.post.mk>

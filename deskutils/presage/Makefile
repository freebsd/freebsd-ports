PORTNAME=	presage
DISTVERSION=	0.9.1
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Intelligent predictive text entry system

BUILD_DEPENDS=	help2man:misc/help2man \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libtinyxml.so:textproc/tinyxml \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

USES=		gmake gnome libtool:build localbase shebangfix python:3.6+ sqlite
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango

SHEBANG_FILES=	apps/dbus/presage_dbus_python_demo \
		apps/dbus/presage_dbus_python_demo.in \
		apps/dbus/presage_dbus_service \
		apps/dbus/presage_dbus_service.py  \
		apps/python/presagemate/presagemate.py \
		apps/python/pypresagemate.in \
		apps/python/pyprompter.in \
		bindings/python/presage_python_demo.in

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation \
		--disable-gprompter \
		--disable-static
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	soothsayer # man/man1/text2ngram.1.gz

.include <bsd.port.mk>

PORTNAME=	presage
DISTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Intelligent predictive text entry system
WWW=		https://presage.sourceforge.io/

BUILD_DEPENDS=	help2man:misc/help2man \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libtinyxml.so:textproc/tinyxml \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

USES=		gmake libtool:build localbase shebangfix python sqlite

SHEBANG_FILES=	apps/dbus/presage_dbus_python_demo \
		apps/dbus/presage_dbus_python_demo.in \
		apps/dbus/presage_dbus_service \
		apps/dbus/presage_dbus_service.py  \
		apps/python/presagemate/presagemate.py \
		apps/python/pypresagemate.in \
		apps/python/pyprompter.in \
		bindings/python/presage_python_demo.in

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-documentation \
		--disable-gprompter \
		--disable-static
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	soothsayer # share/man/man1/text2ngram.1.gz

.include <bsd.port.mk>

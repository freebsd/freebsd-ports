# Created by: Olivier Duchateau

PORTNAME=	dee
PORTVERSION=	1.2.7
PORTREVISION=	19
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/151383425/ \
	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Model to synchronize multiple instances over DBus

LICENSE=	GPLv3

EXTRA_PATCHES=	${FILESDIR}/dee-1.2.7-deprecated-g_type_class_add_private.patch:-p1 \
		${FILESDIR}/vapi-skip-properties.patch:-p1

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libicutu.so:devel/icu

USES=		compiler:c11 gmake gnome libtool localbase pathfix pkgconfig \
		python:3.5+
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build pygobject3
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-gtk-doc-html \
	--disable-tests \
	--disable-gcov \
	--enable-introspection=yes \
	--without-html-dir

MAKE_ARGS=	PYTHON="${PYTHON_CMD}"

.include <bsd.port.mk>

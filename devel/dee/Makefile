PORTNAME=	dee
PORTVERSION=	1.2.7
PORTREVISION=	22
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
USE_GNOME=	glib20 introspection:build pygobject3

CONFIGURE_ARGS=	--disable-gcov \
		--disable-gtk-doc-html \
		--disable-tests \
		--enable-introspection=yes \
		--without-html-dir
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PYTHON="${PYTHON_CMD}"
USE_LDCONFIG=	yes

.include <bsd.port.mk>

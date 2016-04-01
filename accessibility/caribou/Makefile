# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	caribou
PORTVERSION=	0.4.19
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-glx-1.0.so:graphics/clutter \
		libgee-0.8.so:devel/libgee \
		libxklavier.so:x11/libxklavier
RUN_DEPENDS=	py2?-atspi>=2.1.91:accessibility/py-atspi

USES=		gettext gmake gnome libtool pathfix pkgconfig python:2 \
		shebangfix tar:xz
USE_GNOME=	gtk30 intlhack introspection:build libxml2 \
		libxslt:build pygobject3
SHEBANG_FILES=	tools/fix_gir.py tools/make_schema.py
USE_XORG=	x11 xtst
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-gtk2-module=no
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

.include <bsd.port.mk>

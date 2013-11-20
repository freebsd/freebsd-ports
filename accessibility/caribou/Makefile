# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/accessibility/caribou/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	caribou
PORTVERSION=	0.4.10
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libxklavier.so:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	py*-atspi>=2.1.91:${PORTSDIR}/accessibility/py-atspi

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig shebangfix
SHEBANG_FILES=	tools/fix_gir.py tools/make_schema.py
USE_PYTHON=	yes
USE_XORG=	x11 xtst
USE_GNOME=	gnomehier gtk30 intlhack introspection:build libxml2 \
		libxslt:build pygobject3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-gtk2-module=no
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

.include <bsd.port.mk>

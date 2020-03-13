# Created by: Joe Kelsey
# $FreeBSD$

PORTNAME=	libical
PORTVERSION=	3.0.4
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libical/libical/releases/download/v${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	dual

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lib gnome pathfix perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CMAKE_ARGS=	-DICAL_BUILD_DOCS=false
CFLAGS_amd64=	-fPIC

OPTIONS_DEFINE=		GLIB INTROSPECTION VALA
OPTIONS_DEFAULT=	GLIB INTROSPECTION VALA
OPTIONS_SUB=		yes

VALA_DESC=		Build VALA bindings
VALA_BUILD_DEPENDS=	valac:lang/vala
VALA_CMAKE_BOOL=	ICAL_GLIB_VAPI

INTROSPECTION_DESC=		Build GObject Introspection
INTROSPECTION_USE=		gnome=introspection:build
INTROSPECTION_CMAKE_BOOL=	GOBJECT_INTROSPECTION

GLIB_DESC=		Build GLib bindings
GLIB_USE=		GNOME=glib20,libxml2
GLIB_CMAKE_BOOL=	ICAL_GLIB

PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.mk>

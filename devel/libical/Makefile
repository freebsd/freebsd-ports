PORTNAME=	libical
DISTVERSION=	3.0.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libical/libical/releases/download/v${PORTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols
WWW=		https://github.com/libical

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	dual

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lib cpe gnome pathfix perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes

CPE_VENDOR=	libical_project

MAKE_JOBS_UNSAFE=	yes

CFLAGS_amd64=	-fPIC

OPTIONS_DEFINE=		DOCS GLIB INTROSPECTION VAPI
OPTIONS_DEFAULT=	GLIB INTROSPECTION VAPI
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_CMAKE_BOOL=	ICAL_BUILD_DOCS
DOCSDIR=		${PREFIX}/share/gtk-doc/html/libical-glib

VAPI_USES=		vala:build
VAPI_CMAKE_BOOL=	ICAL_GLIB_VAPI

INTROSPECTION_DESC=		Build GObject Introspection
INTROSPECTION_USE=		gnome=introspection:build
INTROSPECTION_CMAKE_BOOL=	GOBJECT_INTROSPECTION

GLIB_DESC=		Build GLib bindings
GLIB_USE=		GNOME=glib20,libxml2
GLIB_CMAKE_BOOL=	ICAL_GLIB

PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.mk>

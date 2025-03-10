PORTNAME=	libical
DISTVERSION=	3.0.19
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libical/libical/releases/download/v${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols
WWW=		https://github.com/libical/libical

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	dual

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake:testing compiler:c++11-lib cpe gnome pathfix perl5 \
		pkgconfig
CPE_VENDOR=	libical_project
USE_LDCONFIG=	yes
USE_PERL5=	build

DOCSDIR=	${PREFIX}/share/gtk-doc/html/libical-glib

PLIST_SUB=	VERSION=${DISTVERSION}

CMAKE_TESTING_ON=	LIBICAL_BUILD_TESTING

CMAKE_OFF=	LIBICAL_BUILD_TESTING
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_BerkeleyDB \
		CMAKE_DISABLE_FIND_PACKAGE_Doxygen

OPTIONS_DEFINE=		DOCS GLIB INTROSPECTION VAPI
OPTIONS_DEFAULT=	GLIB INTROSPECTION VAPI
OPTIONS_SUB=		yes

GLIB_DESC=		Build GLib bindings
INTROSPECTION_DESC=	Build GObject Introspection

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_CMAKE_BOOL=	ICAL_BUILD_DOCS

GLIB_USE=		GNOME=glib20,libxml2
GLIB_CMAKE_BOOL=	ICAL_GLIB

INTROSPECTION_USE=		gnome=introspection:build
INTROSPECTION_CMAKE_BOOL=	GOBJECT_INTROSPECTION

VAPI_USES=		vala:build
VAPI_CMAKE_BOOL=	ICAL_GLIB_VAPI
VAPI_IMPLIES=		INTROSPECTION

.include <bsd.port.mk>

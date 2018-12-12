# Created by: Joe Kelsey
# $FreeBSD$

PORTNAME=	libical
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libical/libical/releases/download/v${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	dual

LIB_DEPENDS=	libicuuc.so:devel/icu

CFLAGS_amd64=	-fPIC

USES=		cmake compiler:c++11-lib gnome pathfix perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE= yes

BUILD_DEPENDS=	valac:lang/vala \
		gtkdoc-scan:textproc/gtk-doc
USE_GNOME=	introspection:build glib20 libxml2
CMAKE_ARGS+=	-DGOBJECT_INTROSPECTION=true \
		-DICAL_GLIB_VAPI=true \
		-DICAL_BUILD_DOCS=false

.include <bsd.port.mk>

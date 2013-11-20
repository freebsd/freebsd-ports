# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgee/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgee
PORTVERSION=	0.8.6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

NO_STAGE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>

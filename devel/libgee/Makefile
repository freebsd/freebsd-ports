# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
<<<<<<< HEAD
#    $MCom: ports/trunk/devel/libgee/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgee
PORTVERSION=	0.8.6
=======
#    $MCom: ports/trunk/devel/libgee/Makefile 19007 2014-02-16 10:11:57Z kwm $

PORTNAME=	libgee
PORTVERSION=	0.12.0
>>>>>>> 57985ccd1cb7834b6340ccff975c19b18250e348
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

<<<<<<< HEAD
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig
=======
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_XZ=		yes
USES=		gmake libtool pathfix pkgconfig
>>>>>>> 57985ccd1cb7834b6340ccff975c19b18250e348
USE_GNOME=	glib20 gnomehier introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

<<<<<<< HEAD
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

=======
>>>>>>> 57985ccd1cb7834b6340ccff975c19b18250e348
.include <bsd.port.mk>

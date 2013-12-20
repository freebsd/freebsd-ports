# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgee/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgee
PORTVERSION=	0.8.6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>

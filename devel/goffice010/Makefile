# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/goffice/Makefile 18385 2013-04-22 12:56:25Z kwm $

PORTNAME=	goffice
PORTVERSION=	0.10.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	goffice010
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 libgsf ltverhack librsvg2
USES=		gettext pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-lasem=no --with-config-backend=gsettings

PLIST_SUB=	VERSION=${PORTVERSION} SHORT_VER=${SHORT_VER}
SHORT_VER=0.10

MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g'\
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/lib/goffice/${SHORT_VER}/plugins

.include <bsd.port.mk>

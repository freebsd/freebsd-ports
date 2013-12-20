# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/devhelp/Makefile 18912 2013-11-22 10:58:03Z gusi $

PORTNAME=	devhelp
PORTVERSION=	3.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3

USE_XZ=		yes
USE_XORG=	x11
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gconf2 gnomeprefix gtk30 intlhack libxslt
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|gedit-plugin||g' ${WRKSRC}/misc/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdevhelp-3.so.1

.include <bsd.port.mk>


# New ports collection makefile for:	clutter-gtk
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter-gtk
PORTVERSION=	0.10.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/Gtk-2.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-gtk20
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/Gtk-2.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-gtk20
LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gtk20 ltverhack gnomeprefix
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|clutter-x11-0.9|clutter-x11-1.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

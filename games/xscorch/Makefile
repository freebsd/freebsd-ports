# New ports collection makefile for:	xscorch
# Date created:				19 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	xscorch
PORTVERSION=	0.1.2
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		mikmod.2:${PORTSDIR}/audio/libmikmod
.if defined(WITH_GNOME)
LIB_DEPENDS+=	gnome.3:${PORTSDIR}/x11/gnomelibs
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk
.if defined(WITH_GNOME)
CONFIGURE_ARGS+=--with-gnome
.else
CONFIGURE_ARGS+=--without-gnome
.endif
CONFIGURE_ENV+=GTK_CONFIG="${GTK_CONFIG}"
USE_GMAKE=	yes

MAN6=		xscorch.6

.include <bsd.port.mk>

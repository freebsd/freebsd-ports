# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	1.11.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable/ \
		ftp://ftp.netc.pt/pub/freeciv/stable/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable/
.if defined(WITH_GTK)
PKGNAMESUFFIX=	-gtk
.endif

MAINTAINER=	sheldonh@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
.if defined(WITH_GTK)
LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
.if defined(WITH_GTK)
GLIB_CONFIG?=	${LOCALBASE}/bin/gtk12-config
CONFIGURE_ENV=	GTK_CONFIG="${GLIB_CONFIG}"
.else
CONFIGURE_ARGS=	--disable-gtktest
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	1.10.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable_version/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable_version/
.if defined(USE_GTK) && (${USE_GTK} == YES || ${USE_GTK} == yes)
PKGNAMESUFFIX=	-gtk
.endif

MAINTAINER=	sheldonh@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
.if defined(USE_GTK)
LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
.if defined(USE_GTK) && (${USE_GTK} == YES || ${USE_GTK} == yes)
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
.else
CONFIGURE_ARGS=	--disable-gtktest
.endif

.include <bsd.port.mk>

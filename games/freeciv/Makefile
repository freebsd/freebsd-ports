# New ports collection makefile for:	freeciv
# Version required:	1.10.0
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

DISTNAME=	freeciv-1.10.0
.if defined(USE_GTK) && (${USE_GTK} == YES || ${USE_GTK} == yes)
PKGNAME=	freeciv-gtk-1.10.0
.endif
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable_version/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable_version/

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

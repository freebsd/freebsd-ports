# New ports collection makefile for:	gtetrinet
# Date created:				27 Feb 2000
# Whom:					Dan Papasian <bugg@bugg.strangled.net>
#
# $FreeBSD$

PORTNAME=	gtetrinet
PORTVERSION=	0.4
CATEGORIES=	games gnome
MASTER_SITES=	ftp://ftp.netis.com/pub/mirrors1/linuxberg/files/gnome/entertain/ \
		ftp://ftp.sunsite.auc.dk/disk1/linuxberg.com/files/gnome/entertain/

MAINTAINER=	bugg@bugg.strangled.net

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG=	"${X11BASE}/bin/gtk12-config"
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
GNU_CONFIGURE=	yes

.include <bsd.port.mk>

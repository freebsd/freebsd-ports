# Ports collection Makefile for:	gtm
# Date created:				05/28/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		gtm
PORTVERSION=		0.3.1
CATEGORIES=		ftp gnome
MASTER_SITES=		http://www.rnl.ist.utl.pt/~bapm/gtm/files/     \
			http://www.nectar.cc/distfiles/

MAINTAINER=		nectar@FreeBSD.org

# wget is in BUILD_DEPENDS because the configure script checks for it
LIB_DEPENDS=		gnome.3:${PORTSDIR}/x11/gnomelibs               \
			capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter
BUILD_DEPENDS=		wget:${PORTSDIR}/ftp/wget
RUN_DEPENDS=		wget:${PORTSDIR}/ftp/wget

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config

USE_X_PREFIX=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		GTK_CONFIG="${GTK_CONFIG}"
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>

# Ports collection Makefile for:	gtm
# Version required:			0.3.1
# Date created:				05/28/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.1.1.1 1999/03/17 08:30:37 nectar Exp $
#

DISTNAME=		gtm-0.3.1
CATEGORIES=		net gnome
MASTER_SITES=		http://www.rnl.ist.utl.pt/~bapm/gtm/files/     \
			http://www.nectar.cc/distfiles/

MAINTAINER=		nectar@FreeBSD.ORG

# wget is in BUILD_DEPENDS because the configure script checks for it
LIB_DEPENDS=		gnome.1:${PORTSDIR}/x11/gnomelibs
BUILD_DEPENDS=		wget:${PORTSDIR}/net/wget
RUN_DEPENDS=		wget:${PORTSDIR}/net/wget

USE_X_PREFIX=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		GTK_CONFIG="${X11BASE}/bin/gtk12-config"
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>

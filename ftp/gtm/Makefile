# Ports collection Makefile for:	gwget
# Version required:			0.2.0
# Date created:				03/17/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.4 1998/11/14 09:43:26 asami Exp $
#

DISTNAME=		gwget-0.2.0
CATEGORIES=		net
MASTER_SITES=		http://camoes.rnl.ist.utl.pt/~bapm/gwget/      \
			http://www.nectar.com/distfiles/

MAINTAINER=		nectar@FreeBSD.ORG

LIB_DEPENDS=		gnome.1:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=		wget:${PORTSDIR}/net/wget

USE_X_PREFIX=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		GTK_CONFIG="${X11BASE}/bin/gtk12-config"
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>

# New ports collection makefile for:	gtkfig
# Version required:	0.6.0
# Date created:		Tue Nov 17 13:51:11 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $Id: Makefile,v 1.1.1.1 1998/11/19 17:00:26 vanilla Exp $
#

DISTNAME=	gtkfig-0.6.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://k332.feld.cvut.cz/pub/local/lemming/gtkfig/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}" \
		GTK_CONFIG=${X11BASE}/bin/gtk11-config

.include <bsd.port.mk>

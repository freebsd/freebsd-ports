# New ports collection makefile for:	xchat
# Version required:		0.9.1
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.5 1999/01/17 19:57:11 vanilla Exp $
#

DISTNAME=	xchat-0.9.1
CATEGORIES=	net
MASTER_SITES=	http://xchat.linuxpower.org/files/ \
		http://www.ozemail.com.au/~peterzelezny/xchat/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11d-config"

.include <bsd.port.mk>

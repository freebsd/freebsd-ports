# New ports collection makefile for:	xchat
# Version required:		0.5.1
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.4 1998/12/08 21:25:17 sada Exp $
#

DISTNAME=	xchat-0.5.1
CATEGORIES=	net
MASTER_SITES=	http://xchat.linuxpower.org/files/ \
		http://www.spyda.co.za/pub/linux/x11/irc/xchat/ \
		http://www.ozemail.com.au/~peterzelezny/xchat/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gnomeui.1:${PORTSDIR}/x11/gnomelibs

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11d-config"

.include <bsd.port.mk>

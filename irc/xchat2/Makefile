# New ports collection makefile for:	xchat
# Version required:		0.3.1
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.3 1998/11/23 10:47:11 asami Exp $
#

DISTNAME=	xchat-0.3.1
CATEGORIES=	net
MASTER_SITES=	http://users.mentasm.com/~zed/xchat/files/old/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		gnomeui.0:${PORTSDIR}/x11/gnomelibs

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11-config"

.include <bsd.port.mk>

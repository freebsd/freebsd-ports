# New ports collection makefile for:	xchat
# Version required:		0.9.5
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.9 1999/03/31 15:25:59 steve Exp $
#

DISTNAME=	xchat-0.9.5
CATEGORIES=	net
MASTER_SITES=	http://xchat.linuxpower.org/files/ \
		http://www.ozemail.com.au/~peterzelezny/xchat/ \
		http://www.spyda.co.za/pub/linux/x11/irc/xchat/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

USE_X_PREFIX=	yes

post-install:
	strip ${PREFIX}/bin/xchat
.if !defined(NOPORTDOCS)
	@${ECHO} "		"
	@${ECHO} "--------------------------------------------------------"
	@${ECHO} "===> Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${ECHO} "--------------------------------------------------------"
	@${MKDIR} ${PREFIX}/share/doc/xchat && chmod a+rx ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	xchat
# Version required:		1.0.0
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.14 1999/06/28 02:21:21 billf Exp $
#

DISTNAME=	xchat-1.0.0
CATEGORIES=	irc
MASTER_SITES=	http://xchat.linuxpower.org/files/ \
		http://www.ozemail.com.au/~peterzelezny/xchat/ \
		http://www.spyda.co.za/pub/linux/x11/irc/xchat/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome --disable-panel
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

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

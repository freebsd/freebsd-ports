# New ports collection makefile for:	xchat
# Version required:		1.1.2
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.16 1999/07/05 02:30:54 cpiazza Exp $
#

DISTNAME=	xchat-1.1.2
CATEGORIES=	irc
MASTER_SITES=	http://xchat.org/files/beta/ \
		http://xchat.linuxpower.org/files/beta/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome --disable-panel --disable-nls
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

post-install:
	@strip ${PREFIX}/bin/xchat
.if !defined(NOPORTDOCS)
	@${ECHO} "--------------------------------------------------------"
	@${ECHO} "===> Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${ECHO} "--------------------------------------------------------"
	@${MKDIR} ${PREFIX}/share/doc/xchat && chmod a+rx ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.mk>

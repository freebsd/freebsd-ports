# New ports collection makefile for:	xchat
# Version required:		1.1.3
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.18 1999/07/19 03:59:57 cpiazza Exp $
#

DISTNAME=	xchat-1.1.3
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
CONFIGURE_ARGS=	--disable-nls

.if defined(USE_GNOME)
CONFIGURE_ARGS+= --enable-gnome
.if defined(USE_PANEL)
CONFIGURE_ARGS+= --enable-panel
.else
CONFIGURE_ARGS+= --disable-panel
.endif
.else
CONFIGURE_ARGS+= --disable-gnome
.endif

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

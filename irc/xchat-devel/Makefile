# New ports collection makefile for:	xchat
# Version required:		1.1.9
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xchat-1.1.9
CATEGORIES=	irc
MASTER_SITES=	http://xchat.org/files/beta/ \
		http://xchat.linuxpower.org/files/beta/

MAINTAINER=	jim@FreeBSD.org

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
	@${ECHO} "===>   Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${MKDIR} ${PREFIX}/share/doc/xchat && ${CHMOD} a+rx ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.mk>

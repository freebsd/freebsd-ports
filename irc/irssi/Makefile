# New ports collection makefile for:	irssi
# Version required:		0.7.11
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.4 1999/06/19 20:09:23 cpiazza Exp $
#

DISTNAME=	irssi-0.7.11-2
PKGNAME=	irssi-0.7.11
CATEGORIES=	irc
MASTER_SITES=	http://www.sicom.fi/~ikioma/irssi/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/irssi-0.7.11
USE_PERL5=	yes
USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --without-dock --without-pthreads \
		--without-socks --without-textui
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

post-install:
	@${ECHO} "		"
	@${ECHO} "---------------------------------------------------------------------------"
	@${ECHO} "===> Installing example irssi.conf to ${PREFIX}/share/examples/irssi"
	@${ECHO} "===> You will find a ~/.irssi.conf after running irssi for the first time."
	@${ECHO} "---------------------------------------------------------------------------"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/examples/irssi && chmod a+rx ${PREFIX}/share/examples/irssi
	${INSTALL_DATA} ${WRKSRC}/irssi.conf ${PREFIX}/share/examples/irssi
	strip ${PREFIX}/bin/irssi
	strip ${PREFIX}/bin/irssi-bot

.include <bsd.port.mk>

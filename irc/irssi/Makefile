# New ports collection makefile for:	irssi
# Version required:		0.7.13
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	irssi-0.7.13-2
PKGNAME=	irssi-0.7.13
CATEGORIES=	irc
MASTER_SITES=	http://xlife.dhs.org/irssi/files/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-pthreads --without-socks --without-textui

.if defined(USE_GNOME)
CONFIGURE_ARGS+= --with-gnome
.if defined(USE_PANEL)
CONFIGURE_ARGS+= --with-gnome-panel
.else
CONFIGURE_ARGS+= --without-gnome-panel
.endif
.else
CONFIGURE_ARGS+= --without-gnome
.endif

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

post-install:
	@${ECHO} "===>   Installing example irssi.conf to ${PREFIX}/share/examples/irssi"
	@${ECHO} "===>   You will find a ~/.irssi.conf after running irssi for the first time."
	@${MKDIR} ${PREFIX}/share/examples/irssi && ${CHMOD} a+rx ${PREFIX}/share/examples/irssi
	@${INSTALL_DATA} ${WRKSRC}/irssi.conf ${PREFIX}/share/examples/irssi

.include <bsd.port.mk>

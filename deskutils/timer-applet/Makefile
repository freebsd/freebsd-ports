# New ports collection makefile for:	timer-applet
# Date created:		2005-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timer-applet
PORTVERSION=	1.3.1
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	timerapplet

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A timer applet for the GNOME panel

LIB_DEPENDS=	notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/share/sounds/gtk-events/clicked.wav:${PORTSDIR}/audio/gnome-audio

USE_GNOME=	gnomehack gnomeprefix gnomepanel intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
GCONF_SCHEMAS=	timer-applet.schemas
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/pixmaps/|${PREFIX}/share/pixmaps/|' \
		${WRKSRC}/GNOME_TimerApplet.server.in.in

.include <bsd.port.mk>

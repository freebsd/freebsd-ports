# New ports collection makefile for:	timer-applet
# Date created:		2005-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timer-applet
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	timerapplet

MAINTAINER=	jylefort@brutele.be
COMMENT=	Timer applet for the Gnome panel

RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/gtk-events/clicked.wav:${PORTSDIR}/audio/gnomeaudio2

USE_GNOME=	gnomehack gnomeprefix gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec	# applets belong to libexec
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/pixmaps/||; \
		 s|location="timer-applet"|location="${PREFIX}/libexec/timer-applet"|' \
		${WRKSRC}/timer-applet.server
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/sounds|${X11BASE}/share/gnome/sounds|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

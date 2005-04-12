# New ports collection makefile for:	timer-applet
# Date created:		2005-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timer-applet
PORTVERSION=	1.0
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	timerapplet

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A timer applet for the GNOME panel

RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/gtk-events/clicked.wav:${PORTSDIR}/audio/gnomeaudio2

USE_GNOME=	gnomehack gnomeprefix gnomepanel intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec	# applets belong to libexec
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GCONF_SCHEMAS=	timer-applet.schemas
INSTALLS_OMF=	yes
OMFDIR=		${PREFIX}/share/gnome/omf/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/pixmaps/|${PREFIX}/share/gnome/pixmaps/|; \
		 s|location="timer-applet"|location="${PREFIX}/libexec/timer-applet"|' \
		${WRKSRC}/GNOME_TimerApplet.server.in
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/sounds|${X11BASE}/share/gnome/sounds|' \
		${WRKSRC}/src/Makefile.in
	@${MKDIR} ${WRKSRC}/omf-install

post-install:
	${MKDIR} ${OMFDIR}
.for lang in C fr
	${INSTALL_DATA} ${WRKSRC}/omf-install/${PORTNAME}-${lang}.omf ${OMFDIR}
	-scrollkeeper-install -q ${OMFDIR}/${PORTNAME}-${lang}.omf
.endfor

.include <bsd.port.mk>

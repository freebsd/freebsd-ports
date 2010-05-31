# New ports collection makefile for:	timer-applet
# Date created:		2005-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timer-applet
PORTVERSION=	2.1.2
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	SF/timerapplet/timerapplet/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A timer applet for the GNOME panel

RUN_DEPENDS=	${LOCALBASE}/share/sounds/gtk-events/clicked.wav:${PORTSDIR}/audio/gnome-audio \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify

USE_GNOME=	gnomehack gnomeprefix intlhack pygnomedesktop
USE_PYTHON=	2.5+
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec

GCONF_SCHEMAS=	timer-applet.schemas

.include <bsd.port.mk>

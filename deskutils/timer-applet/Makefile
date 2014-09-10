# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	timer-applet
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/52401395/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Timer applet for the GNOME panel

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	gnome-audio>0:${PORTSDIR}/audio/gnome-audio \
		${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}notify>0:${PORTSDIR}/devel/py-notify

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gettext gmake pathfix
USE_GNOME=	gnomeprefix intlhack pygnomedesktop
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec --disable-schemas-install

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	timer-applet.schemas

.include <bsd.port.mk>

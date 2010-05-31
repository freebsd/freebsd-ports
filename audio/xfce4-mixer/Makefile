# New ports collection makefile for:	xfce4-mixer
# Date created:		3 July 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mixer
PORTVERSION=	4.6.1
PORTREVISION=	5
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 volume mixer module for xfce4-panel

BUILD_DEPENDS+=	gstreamer-plugins-good>=0.10.22:${PORTSDIR}/multimedia/gstreamer-plugins-good
RUN_DEPENDS+=	gstreamer-plugins-good>=0.10.22:${PORTSDIR}/multimedia/gstreamer-plugins-good

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack libxml2 pkgconfig
USE_XFCE=	configenv libgui libutil panel xfconf
USE_XORG=	xproto x11 xrender xext xinerama xrandr xcursor xcomposite \
		xdamage xfixes xi xau xdmcp

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.mk>

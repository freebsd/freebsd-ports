# New ports collection makefile for:	xfce4-mixer
# Date created:		3 July 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mixer
PORTVERSION=	4.8.0
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 volume mixer module for xfce4-panel

BUILD_DEPENDS+=	gstreamer-plugins-good>=0.10.22:${PORTSDIR}/multimedia/gstreamer-plugins-good
RUN_DEPENDS+=	gstreamer-plugins-good>=0.10.22:${PORTSDIR}/multimedia/gstreamer-plugins-good

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack libxml2 pkgconfig
USE_XFCE=	configenv libgui libutil panel xfconf
USE_XORG=	xproto x11 xrender xext xinerama xrandr xcursor xcomposite \
		xdamage xfixes xi xau xdmcp

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.mk>
